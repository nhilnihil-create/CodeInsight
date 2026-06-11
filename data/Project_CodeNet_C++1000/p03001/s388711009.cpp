#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    double w,h,x,y;
    cin >> w >> h >> x >> y;
    int flag=0;
    if(w==(x*2) && h==(y*2)) flag=1;
    cout << fixed << setprecision(15) << (w*h)/2 << " " << flag << "\n";
    return 0;
}   