#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<int>a(n);
    rep(i, n)   cin >> a[i];
    map<int, int>m;
    ll ans = 0;
    rep(i, n){
        int s = i-a[i];
        int w = a[i]+i;
        ans += m[s];
        m[w]++;
    }
    cout << ans << endl;
}
