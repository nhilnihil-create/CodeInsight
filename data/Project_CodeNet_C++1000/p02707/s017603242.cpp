#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long ;
int main(){
    int n;
    cin >> n;
    vector<int> joushi(n);
    rep(i,n-1){
        int a;
        cin >> a;
        a--;
        joushi[a]++;
    }
    rep(i,n) cout << joushi[i] << endl;
}