
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    ll n, k;
    cin >> n >> k;
    ll count =0;
    while(true){
        n /= k;
        count ++;
        if(n==0) break;
    }

    cout << count << endl;
}