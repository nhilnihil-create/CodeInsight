#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
const int INF=1e9;

int main(){
    string s;cin>>s;
    ll bg=0,sm=0;
    ll ans=0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='<') bg++;
        else sm++;

        if(i==(int)s.size()-1||(s[i]=='>'&&s[i+1]=='<')){
            ll M=max(bg,sm),m=min(bg,sm);
            ans+=M*(M+1)/2;
            ans+=m*(m-1)/2;
            bg=sm=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}