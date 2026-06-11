#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

lli n;
vll a;
vll g;
lli ans = 0;

int main(){
    cin >> n;
    a = vll(n);
    for(lli i = 0;i < n;i++) cin >> a[i];
    for(lli i = 1;i <= n;i = 3*i+1){
        g.push_back(i);
    }
    for(lli k = g.size()-1;k >= 0;k--){
        for(lli i = 0;i < n;i++){
            for(lli j = i-g[k];j >= 0 && a[j] > a[j+g[k]];j-=g[k]){
                swap(a[j],a[j+g[k]]);
                ans++;
            }
        }
    }
    cout << g.size() << endl;
    cout << g[g.size()-1];
    for(lli i = g.size()-2;i >= 0;i--){
        cout << " " << g[i];
    }
    cout << endl;
    cout << ans << endl;
    for(lli i = 0;i < n;i++) cout << a[i] << endl;
    return 0;
}