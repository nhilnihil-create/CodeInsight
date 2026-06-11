#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N; cin>>N;
    for (ll i = floor(sqrt(N)); i > 0; i--){
        if(N%i==0){
            cout<<(i-1)+(N/i-1)<<endl;
            return 0;
        }
    }
}