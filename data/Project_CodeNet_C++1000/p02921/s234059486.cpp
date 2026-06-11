#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    string S,T; cin>>S>>T;
    ll ans=0;
    for(int i=0;i<3;i++){
        if(S[i]==T[i]) ans++;
    }
    cout<<ans<<endl;
}