#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI=acos(-1);
const int INF = numeric_limits<int>::max();

int main(){
    int n, d[100];
    cin >> n;

    rep(i,n) cin >> d[i];

    int sum = 0;

    rep(i,n){
        for (int j = i+1; j < n; ++j){
            sum += d[i] * d[j];
        }
    }

    cout << sum << endl;

    return 0;
    
}