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

    int cnt = 0;
    int min = n+1;
    rep(i,n){
        int p;
        cin >> p;
        if (p < min){
            cnt++;
            min = p;
        }
    }
    cout << cnt << endl;
    return 0;
}
