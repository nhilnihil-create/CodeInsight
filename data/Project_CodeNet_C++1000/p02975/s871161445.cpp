#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N;
    cin >> N;
    vector<ll> a(N ,0);
    ll ans = 0;
    for(int i = 0; i < N ; i++){
        cin >> a[i];
        ans ^= a[i];
    }
    if(ans == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
}
