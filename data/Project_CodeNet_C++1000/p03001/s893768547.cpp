#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    double w, h; cin >> w >> h;
    int x, y; cin >> x >> y;
    cout << h * w / 2 << " " << (x * 2 == w && y * 2 == h ? 1 : 0) << endl;
}
