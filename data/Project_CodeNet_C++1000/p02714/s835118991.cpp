#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0;i<n;i++)
#define ll long long
char solve(char c1,char c2){
	if(c1=='R'&&c2=='G') return 'B';
	if(c1=='G'&&c2=='R') return 'B';

	if(c1=='B'&&c2=='G') return 'R';
	if(c1=='G'&&c2=='B') return 'R';

	if(c1=='R'&&c2=='B') return 'G';
	if(c1=='B'&&c2=='R') return 'G';

	return ' ';
}
struct color{
	int r=0;
	int g=0;
	int b=0;

};
typedef struct color color;
int main(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	int size = s.length();
	vector<color>v(size);
	ll totalR=0,totalG=0,totalB=0;
	//initialize
	if(s[0]=='R') {v[0].r = 1;totalR++;}
	if(s[0]=='G') {v[0].g = 1;totalG++;}
	if(s[0]=='B') {v[0].b = 1;totalB++;}

	for(int i = 1;i<n;i++){
		v[i].r = v[i-1].r;
		v[i].g = v[i-1].g;
		v[i].b = v[i-1].b;
		if(s[i]=='R'){
			totalR++;
			v[i].r = v[i-1].r + 1;
		}
		if(s[i]=='G'){
			totalG++;
			v[i].g = v[i-1].g + 1;
		}	
		if(s[i]=='B'){
			totalB++;
			v[i].b = v[i-1].b + 1;
		}
	}
	// cout<<"HERE";
	// f(i,s.length()){
	// 	cout<<i<<" "<<v[i].r<<" "<<v[i].g<<" "<<v[i].b<<endl;	
	// }
	// cout<<"BEGIN"<<endl;
	// cout<<"totals "<<totalR<<" "<<totalB<<" "<<totalG<<endl;
	f(i,s.length()){
		v[i].r = totalR-v[i].r;
		v[i].g = totalG-v[i].g;
		v[i].b = totalB-v[i].b;
		// cout<<i<<" "<<v[i].r<<" "<<v[i].g<<" "<<v[i].b<<endl;
	}
	// cout<<"HERE1";
	ll count = 0;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<(n-1);j++){
			char ch = solve(s[i],s[j]);
			// cout<<i<<" "<<j<<" "<<ch<<" ";
			// cout<<endl;
			int key = 2*j-i;
			if(ch=='R'){
				count = count+v[j].r;
				if(key<n)
				if(s[2*(j)-(i)]=='R') count--;
			}
			if(ch=='G'){
				// cout<<"J "<<j<<v[j].g<<endl;
				count = count+v[j].g;
				if(key<n)
				if(s[2*j-i]=='G') count--;
			}
			if(ch=='B'){
				count = count+v[j].b;
				if(key<n)
				if(s[2*j-i]=='B') count--;
			}
			// cout<<count<<endl;
		}
	}

	cout<<count;
	

}