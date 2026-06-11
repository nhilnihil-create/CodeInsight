#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    string s;
    cin>>s;
    int flag=1;
    for(int i=0;i<s.size();++i){
        if(((i&1)==0 && s[i]=='L') || (i&1 && s[i]=='R') ){
            flag=0;
            break;
        }
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}