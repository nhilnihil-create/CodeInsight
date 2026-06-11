
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n-1; i++){
        cin >> a.at(i+1);
    }

    vector<int> res(n);
    for(int i=1; i<n; i++){
        res.at(a.at(i)-1) ++;
    }
    rep(i,n){
        cout << res.at(i) << endl;
    }
}