#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    ll sum = 0;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        sum ^= a[i];
    }
    if(sum == 0){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}