#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
bool x=false;
set<int>se;
void ch(int n){
	if(x) return ;
	for(int i=1;i<=(int)sqrt(n);++i){
		if(n%i==0){
			if(i==1){
				if(se.count(n/i)) x=true;
				se.insert(n/i);
			}
			else{
				if(se.count(n/i)) x=true;
				if(se.count(i)) x=true;
				se.insert(i);
				se.insert(n/i);
			}
		}
	}
}
int main(){
	nes;
	int n;
	cin>>n;
	vector<int>v1(n);
	for(int i=0;i<n;++i) cin>>v1[i];
	int p=v1[0];
	for(int i=0;i<n;++i){
		p=__gcd(p,v1[i]);
		if(v1[i]!=1)
		ch(v1[i]);
	}
	if(!x) cout<<"pairwise coprime";
	else if(p==1) cout<<"setwise coprime";
	else cout<<"not coprime";
	return 0;
}