#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

ll N, A, B;

signed main(){
    cin >> N >> A >> B;
    if(abs(A-B)%2 == 0){
        cout << abs(A-B)/2 << endl;
    }
    else{
        ll ans = A + abs(1-(B-A))/2;
        A = N+1-A;
        B = N+1-B;
        swap(A, B);
        ans = min(ans, A + abs(1-(B-A))/2);
        cout << ans << endl;
    }
}