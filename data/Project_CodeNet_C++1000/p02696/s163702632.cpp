#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    ll A,B,N; cin>>A>>B>>N;
    
    ll ans=0;
    if(N<B){
        ans = (A*N)/B - A*(N/B);
    }else{
        ans =(A*(B-1))/B - A*((B-1)/B);
    }
    
    cout << ans << endl;
}
