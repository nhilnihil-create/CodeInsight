#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    double sum = 0;
    rep(i, n){
        cin >> v.at(i);
        sum += v.at(i);
    }
    int ave = round(sum / (double)n);
    int ans = 0;
    rep(i, n){
        ans = ans + pow(ave-v.at(i), 2);
    }
    cout << ans << endl;

    return 0;
}
