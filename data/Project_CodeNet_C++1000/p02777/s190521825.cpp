#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const ll MOD=(ll)1e9+7;

int main(){
    string S, T; cin >> S >> T;
    int A, B; cin >> A >> B;
    string U; cin >> U;
    ll res1=A, res2=B;
    if(U == S) res1--;
    else res2--;
    cout << res1  << " " << res2 << endl;
    return 0;
}