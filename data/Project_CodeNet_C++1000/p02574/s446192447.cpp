#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

vector<int> sieve(int n) {
    vector<int> res(n);
    for(int i = 0; i < n; ++i) res[i] = i;
    for (int i = 2; i*i < n; ++i) {
        if (res[i] < i) continue;
        for (int j = i*i; j < n; j += i)
        if (res[j] == j) res[j] = i;
    }

    return res;
}

vector<int> factor(int n, const vector<int>& min_factor) {
    vector<int> res;
    while (n > 1) {
        res.push_back(min_factor[n]);
        n /= min_factor[n];
    }

    return res;
}

int main(void){

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int x = a[0];
    for(int i = 0; i < n; ++i) x = gcd(x, a[i]);
    if(x != 1){
        cout << "not coprime" << "\n";
        return 0;
    }

    vector<int> b = sieve(1000005);
    set<int> prime;
    for(int i = 0; i < n; ++i){
        vector<int> c = factor(a[i], b);
        set<int> ps(all(c));
        for(auto v : ps){
            if(prime.find(v) != prime.end()){
                cout << "setwise coprime" << "\n";
                return 0;
            }
            prime.insert(v);
        }
    }

    cout << "pairwise coprime" << "\n";

    return 0;
}
