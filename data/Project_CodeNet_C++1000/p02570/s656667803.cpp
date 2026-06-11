#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint=long long;
int MOD=1000000007;

signed main(){
    int d,t,s;cin>>d>>t>>s;
	if(s*t>=d){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}