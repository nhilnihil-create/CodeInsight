#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int N;string s;cin>>N>>s;
    string ans="";
    rep(i,s.size()){
        if(s.at(i)+N<='Z'){
            ans+=s.at(i)+N;
        }else{
            ans+=s.at(i)+N-'Z'+'A'-1;
        }
    }
    cout<<ans<<endl;
}