#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, M, K;
    cin>> N >> M >> K;

    vector<ll> a(N+1,0);
    for(int i=1; i<=N; i++){
        ll A;
        cin>> A;
        a[i] = a[i-1]+A;
    }

    vector<ll> b(M+1,0);
    for(int i=1; i<=M; i++){
        ll B;
        cin>> B;
        b[i] = b[i-1]+B;
    }

    ll ans = 0;
    ll j = M;
    for(int i = 0; i<=N; i++){
        if(a[i]>K){
            break;
        }
        while(b[j] > K-a[i]){
            j--;
        }
        ans = max(ans, i+j);
    }

    cout<< ans <<endl;
    return 0;
}