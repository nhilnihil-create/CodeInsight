#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n;
    cin >> n;
    vi x(n);
    rep(i,n) cin >> x.at(i);

    int MIN = 1'000'000;
    rep(i,100){
        int sum = 0;
        rep(j,n){
            sum += (x.at(j)-i) * (x.at(j)-i);
        }
        MIN = min(MIN, sum);
    }
    cout << MIN << endl;
    return 0;
}
