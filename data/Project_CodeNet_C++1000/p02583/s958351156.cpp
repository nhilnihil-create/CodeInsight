#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec[i];
    sort( vec.begin(), vec.end() );
    int count = 0;
    rep(i,n) rep(j,i) rep(k,j) {
        if (vec[i] != vec[j] && vec[j] != vec[k] && vec[k] + vec[j] > vec[i]) count++;
    }
    cout << count << endl;
}