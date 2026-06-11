#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    if(N%2){
        ans = N*((N-1)/2);
    }else{
        ans = N*((N-1)/2) + (N-1)/2+1;
    }
    cout << ans << endl;
}