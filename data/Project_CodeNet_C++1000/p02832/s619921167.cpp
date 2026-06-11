
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
    rep(i,n) cin >> a[i];

    int count = 1;
    bool ok=false;
    rep(i,n){
        if(a.at(i)==count){
            count ++;
            ok = true;
        }
    }
    if(ok){
        cout << n - count + 1 << endl;
    }
    else{
        cout << -1 << endl;
    }


}