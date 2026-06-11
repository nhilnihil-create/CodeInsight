#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=2e3+10;
ll L[Maxn],ans,N;
bool vis[Maxn];
bool check(ll i,ll j,ll k){
    return L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[k] + L[j] > L[i];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>N;
    for(ll i=1;i<=N;i++)    cin>>L[i];
    sort(L+1,L+N+1);
    for(ll i=1;i<=N;i++){
        bool f=0;
        for(ll j=i+1;j<=N;j++){
            for(ll k=j+1;k<=N;k++){
                if(check(i,j,k)) ans++;
                else{
                    f=1;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
