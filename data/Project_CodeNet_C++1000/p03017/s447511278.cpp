#include <bits/stdc++.h>
using namespace std;
#define int long long




signed main() {
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    int t=0;
    for(int i=a-1;i<c-1;i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            t=1;
            break;
        }
    }
    for(int i=b-1;i<d-1;i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            t=1;
            break;
        }
    }
    if(t==0&&d<c){
        t=1;
        for(int i=b-1;i<=d-1;i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i-1]=='.'){
                t=0;
                break;
            }
        }
    }
    if(t==0)cout<<"Yes";
    else cout<<"No";
   return 0;
}
