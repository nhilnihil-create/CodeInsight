#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i=0;i<(n);i++)

int main() {
    string S;
    cin>>S;
    vector<int> amari(2019,-1);
    amari[0]=1;
    int amari_now=0,ans=0,kurai_mod=1;
    for(int i=S.size();i>0;i--){
        int t = stoi(S.substr(i-1,1));
        amari_now=(t*kurai_mod+amari_now)%2019;
        if(amari[amari_now]==-1){
            amari[amari_now]=1;
        }else{
            ans+=amari[amari_now];
            amari[amari_now]++;
        }
        kurai_mod=(kurai_mod*10)%2019;
    }
    cout << ans << endl;
}