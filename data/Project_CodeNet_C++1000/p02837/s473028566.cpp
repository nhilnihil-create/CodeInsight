#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
vector<pair<int,int> >v[16];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		for(int j=0;j<a;j++){
			int x;char y;cin>>x>>y;
			v[i].push_back({x,y});
		}
	}
	int ans=0;
	int k=(1<<n);
	for(int i=0;i<k;i++){
		int tmp=i;
		string s="";
		int cnt=0;
		while(tmp){
			if(tmp%2){s+='1';cnt++;}
			else s+='0';
			tmp/=2;
		}
		while(s.length()<n)s+='0';
		bool hnhn=false;
		for(int j=0;j<s.length();j++){
			bool t=false;
			if(s[j]=='1'){
				for(auto u:v[j+1]){
					if(s[u.first-1]!=u.second){
						t=true;
						break;
					}
				}
			}
			if(t){hnhn=true;break;}
		}
		if(!hnhn){
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}