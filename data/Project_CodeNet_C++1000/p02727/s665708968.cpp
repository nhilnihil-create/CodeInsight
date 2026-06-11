#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
#define ALL(a)  (a).begin(),(a).end()
//小数点の表し方 cout << fixed << setprecision(5);


int main(){
    int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a),q(b),r(c),s;
    for(int i=0;i<a;i++){
        cin >> p[i];
    }
    for(int i=0;i<b;i++){
        cin >> q[i];
    }
    for(int i=0;i<c;i++){
        cin >> r[i];
    }
    sort(ALL(p),greater<int>());
    sort(ALL(q),greater<int>());
    //sort(ALL(r),greater<int>());
    for(int i=0;i<x;i++){
        r.push_back(p[i]);
    }
    for(int i=0;i<y;i++){
        r.push_back(q[i]);
    }
    sort(ALL(r),greater<int>());
    ll ans = 0;
    for(int i=0;i<x+y;i++){
        ans += r[i];
    }
    cout << ans << endl;
    
}