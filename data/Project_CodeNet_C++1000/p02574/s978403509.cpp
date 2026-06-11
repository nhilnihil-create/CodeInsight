#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;

map<int, int> primeFactorization(int n){
    map<int, int> ret;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
        ret[i]++;
        n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    map<int, int> primes;
    for(auto x : a){
        auto tmp = primeFactorization(x);
        for(auto y : tmp){
            primes[y.first]++;
        }
    }

    string ans = "pairwise coprime";
    bool flag1 = false;
    for(auto x : primes){
        if(x.second == n){
            ans = "not coprime";
            break;
        }
        if(x.second != 1){
            ans = "setwise coprime";
        }
    }

    cout << ans << endl;
    return 0;
}
