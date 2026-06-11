#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n, k;
    cin >> n >> k;
    vector<double> p(n+1);
    for(int i = 1; i < n+1; ++i){
        int a;
        cin >> a;
        p[i] = (a * (a + 1) / 2) / (double)a;
    }

    for(int i = 1; i <= n; ++i){
        p[i] += p[i - 1];
    }

    double ans = 0;
    for(int i = 0; i < n-k+1; ++i){
        ans = max(ans, p[i + k] - p[i]);
    }

    cout << fixed << setprecision(15) << ans << "\n";

    return 0;
}
