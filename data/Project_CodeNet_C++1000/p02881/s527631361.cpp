#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    ll N; cin >> N;
    ll min = 1e13;
    for (ll i = 1;i * i <= N;i++){
        if ((N % i) == 0){
            ll a,b;
            a = i;
            b = N /i;
            ll tmp = abs(a-1) + abs(b-1);
            if (tmp < min){
                min = tmp;
            }
        }
    }
    cout << min << endl;
    return 0;
}