#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    for (int i = 0; i<5; i++){
        if(a[i]==0){
          cout << i+1 << endl;
        }
    }
    return 0;
}