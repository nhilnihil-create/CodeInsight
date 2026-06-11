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
    vi a(n);
    rep(i,n-1){
        int ai;
        cin >> ai;
        a.at(ai-1)++;
    }
    rep(i,n) cout << a.at(i) << endl;
    return 0;
}
