#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    double a, b;
    cin >> a >> b;
    
    rep(i,1300){
        int x, y;
        x = i * 0.08;
        y = i * 0.1;
        if (x == a && y == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
