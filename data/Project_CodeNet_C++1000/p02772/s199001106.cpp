
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

    rep(i,n){
        if(a[i]%2==0 && a[i]%3!=0 && a[i]%5!=0){
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;
}