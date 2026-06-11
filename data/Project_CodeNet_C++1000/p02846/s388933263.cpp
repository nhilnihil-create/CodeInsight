#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll A1 = t1 * a1;
    ll A12 = A1 + t2 * a2;
    ll B1 = t1 * b1;
    ll B12 = B1 + t2 * b2;

    //無限に続く
    if(A12 == B12){
        cout << "infinity" << endl;
        return 0;
    }

    if(A12 < B12){
        swap(A12, B12);
        swap(A1, B1);
    }

    ll ans = 0;
    if(A1 > B1){
        //永遠に交わらない
        cout << "0" << endl;
    }else if(A1 < B1){
        //交わるところが出てくる
        if((B1-A1) % (A12-B12) != 0){
            ans = (B1-A1) / (A12-B12)  * 2 + 1;
        }else{
            ans = (B1-A1) / (A12-B12) * 2;
        }
        cout << ans << endl;
    }
}