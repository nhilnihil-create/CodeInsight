#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k,R,S,P;
    string t;
    cin>>n>>k>>R>>S>>P>>t;

    int ans=0;
    string s="";
    rep(i,n){
        if(i<k){
            if(t[i]=='r') ans+=P, s+='p';
            else if(t[i]=='s') ans+=R, s+='r';
            else ans+=S, s+='s';
        }
        else{
            if(t[i]!=t[i-k]){
                if(t[i]=='r') ans+=P, s+='p';
                else if(t[i]=='s') ans+=R, s+='r';
                else ans+=S, s+='s';
            }
            else{
                if(t[i]=='r'){
                    if(s[i-k]=='p') s+='r';
                    else ans+=P, s+='p';
                }
                else if(t[i]=='s'){
                    if(s[i-k]=='r') s+='s';
                    else ans+=R, s+='r';
                }
                else{
                    if(s[i-k]=='s') s+='p';
                    else ans+=S, s+='s';
                }
            }
        }
    } 
    //cout<<s<<endl;
    cout<<ans<<endl;
}
