
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    int order=0;

    rep(i,n){
        int a;
        cin >> a;
        if(a!=i+1) order ++;
    }

    if(order<=2){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}