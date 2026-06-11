#include <bits/stdc++.h>
#define rep(i,n) for(ll i = -1000; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    ll N; cin >> N;
    bool flag = false;
    rep (i,1000){
        rep (j,1000){
            ll tmp = pow(i,5) - pow(j,5);
            if (tmp == N){
                cout << i << " " << j << endl;
                flag = true;
                break;
            }
        }
        if (flag == true){
            break;
        }
    }

    return 0;
}