#include <iostream>
#include <vector>
#include <numeric>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n,k;
    cin >>n>>k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    sort(p.begin(), p.end());
    int ans;
    ans = accumulate(p.begin(), p.begin()+k,0);
    cout << ans << endl;
}