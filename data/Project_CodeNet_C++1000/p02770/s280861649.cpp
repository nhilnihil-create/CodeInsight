#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
const int MAXN = 5e3+6;
ll d[MAXN], dm[MAXN], sbloco;
int main(){
    fastio;
    int k,q; cin>>k>>q;
    for(int i=0; i<k; i++)cin>>d[i];
    while(q--){
        ll ni,xi,mi; cin>>ni>>xi>>mi;
        xi = xi%mi;
        sbloco = 0;
        for(int i=0; i<k; i++){
            int aux = d[i]%mi;
            dm[i] = (aux==0) ? mi : aux;
            sbloco += dm[i]; 
        }
        ll num_blocos = (ni - 1)/k;//quantos blocos completos
        ll ans = xi + num_blocos*sbloco;
        for(int i=0; i<(ni-1)%k; i++){
            ans += dm[i];
        }
        cout << ni - 1 - ans/mi << endl;
    }
}