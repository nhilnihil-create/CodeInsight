#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main(){
	string s,t;cin>>s>>t;
	int Min=INT_MAX;
	rep(i,s.size()-t.size()+1){
		int cnt=0;
		rep(j,t.size()){
			cnt+=(s[i+j]!=t[j]);
		}
		Min=min(Min,cnt);
	}
	cout<<Min<<endl;
}