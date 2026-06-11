#include<bits/stdc++.h>
#define int long long
#define double long double
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

signed main(){
    int k, n;
    cin >> n >> k;
    vector<double> kitai(n);
    vector<double> kitaiwa(n+1);

    rep(i, n){
        int tmp;
        cin >> tmp;
        kitai[i] = (1.0+tmp)/2.0;
        kitaiwa[i+1] = kitaiwa[i] + kitai[i];
    }

    double ans = 0;

    rep(i, n + 1 - k){
        int right = i + k;
        double tmp_sum = kitaiwa[right] - kitaiwa[i];
        ans = max(ans, tmp_sum);
    }

    cout << fixed << setprecision(10) << ans << endl;

}