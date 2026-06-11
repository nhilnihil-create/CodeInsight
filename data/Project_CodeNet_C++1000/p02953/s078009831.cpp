#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> H(N);
    for(int i=0; i<N; i++)cin >> H[i];
    ll maxh = 0;
    bool check = true;
    ll cnt = 0;
    for (int i = 1; i < N; i++) {
        if(H[i]==H[i-1]-1){
          H[i]++;
        }
        else if(H[i]<H[i-1]-1){
          check = false;
          break;
        }
    }
    if(check) cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
}