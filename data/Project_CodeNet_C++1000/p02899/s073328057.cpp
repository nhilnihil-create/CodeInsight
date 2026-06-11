#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vect;
    rep(i, n){
        ll input;
        cin >> input;
        vect.push_back(make_pair(input, i +1));
    }

    sort(vect.begin(), vect.end());

    rep(i, n){
        if(i == n-1){
            cout << vect[i].second << endl;
        }else{
            cout << vect[i].second << " ";
        }
    }
}