#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,r,s,p,ans;
string t;
int main(void){
    cin>>n>>k>>r>>s>>p>>t;
    for(int i=0;i<t.size();i++){
        if(i>=k){
            if(t[i]=='r'){
                if(t[i-k]=='r'){
                    t[i]='x';
                }else{
                    ans+=p;
                }
            }else if(t[i]=='s'){
                if(t[i-k]=='s'){
                    t[i]='x';
                }else{
                    ans+=r;
                }
            }else{
                if(t[i-k]=='p'){
                    t[i]='x';
                }else{
                    ans+=s;
                }
            }
        }else{
            if(t[i]=='r'){
                ans+=p;
            }else if(t[i]=='s'){
                ans+=r;
            }else{
                ans+=s;
            }
        }
    }
    cout<<ans<<endl;

}
