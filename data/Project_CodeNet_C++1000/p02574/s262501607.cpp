#include<bits/stdc++.h>
using namespace std;
#define gcd __gcd
void solve(){
	long n;
	cin>>n;
	map<long,long> m1;
	long temp;
	int a=0;
	long g;
	long x;
	long cnt=0;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(i==0){
			g=temp;
		}else{
			g=gcd(g,temp);
		}
		x=temp;
		cnt=0;
		while(x%2==0){
			if(cnt==0&&m1[2]){
				a=1;
				cnt++;
			}
			m1[2]=1;
			cnt++;
			x=x/2;
		}
		for(int j=3;j<=sqrt(x);j=j+2){
			cnt=0;
			while(x%j==0){
				if(cnt==0&&m1[j]){
					a=1;
					cnt++;
				}
				m1[j]=1;
				x=x/j;
				cnt++;
			}
		}
		if(x>1){
			if(m1[x]){
				a=1;
			}
			m1[x]=1;
		}
	}
	if(a==0){
		cout<<"pairwise coprime\n";
	}else if(a==1&&g==1){
		cout<<"setwise coprime\n";
	}else{
		cout<<"not coprime\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long t=1;
//	cin>>t;
	while(t--)
		solve();
}