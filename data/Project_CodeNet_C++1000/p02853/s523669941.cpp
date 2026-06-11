#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int x,y;
    cin>>x>>y;

    vector<int> v = {0,300000,200000,100000,0};
    int res = 0;
    if (x==1&&y==1) res+=400000;

    x = min(x,4);
    y = min(y,4);
    res += v[x];
    res += v[y];
    cout<<res<<endl;    
    return 0;
}
