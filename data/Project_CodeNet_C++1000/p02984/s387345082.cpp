#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=1e5+10;
ll A[Maxn],sum[2][Maxn];
int main() {
    ios::sync_with_stdio(false);
    ll N = 0;
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>A[i];
        if(i%2){
            sum[0][i]=sum[0][i-1]+A[i];
            sum[1][i]=sum[1][i-1]-A[i];
        }else{
            sum[0][i]=sum[0][i-1]-A[i];
            sum[1][i]=sum[1][i-1]+A[i];
        }
    }
    for(ll i=1;i<=N;i++){
        if(i%2){
            cout<<sum[1][i-1]+(sum[0][N]-sum[0][i-1])<<" ";
        }else{
            cout<<sum[0][i-1]+(sum[1][N]-sum[1][i-1])<<" ";
        }
    }
    return 0;
}
