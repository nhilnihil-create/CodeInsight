#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
string s[100005];
int t[100005];
string S;
bool x=false;
ll ans;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>t[i];
    }
    cin>>S;
    for(int i=0;i<n;i++){
        if(x) ans+=t[i];
        if(s[i]==S){
            x=true;
        }
    }
    cout<<ans<<endl;
    
}
