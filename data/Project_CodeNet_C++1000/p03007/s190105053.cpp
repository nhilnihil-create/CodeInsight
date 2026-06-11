#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for(ll& x: A) cin >> x;

    sort(A.begin(), A.end());
    ll ans = 0;
    vector<Pll> ope;
    bool flag = false;
    if(A[0] >= 0){
        ans = A[0];
        for(int i=1; i<N-1; i++){
            ope.emplace_back(ans, A[i]);
            ans -= A[i];
        }
        ope.emplace_back(A[N-1], ans);
        ans = A[N-1] - ans;
    }
    else if(A[N-1] <= 0){
        ans = A[N-1];
        for(int i=N-2; i>=0; i--){
            ope.emplace_back(ans, A[i]);
            ans -= A[i];
        }
    }
    else{
        int j = distance(A.begin(), upper_bound(A.begin(), A.end(), 0));
        ans = A[0];
        bool flag = false;
        for(int i=N-1; i>0; i--){
            if(i == j){
                flag = true;
                ope.emplace_back(A[i], ans);
                ans = A[i] - ans;
            }
            else{
                ope.emplace_back(ans, A[i]);
                ans -= A[i];
            }
        }
    }

    cout << ans << endl;
    for(Pll& p: ope) cout << p.first << " " << p.second << endl;
}