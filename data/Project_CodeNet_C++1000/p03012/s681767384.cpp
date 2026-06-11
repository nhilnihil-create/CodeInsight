#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i, n){
        cin >> w[i];
    }
    int diff = 10000000;
    rep(i, n){
        int x = 0, y = 0;
        for (int j = 0; j < i; j++){
            x += w[j];
        }
        for (int j = i; j < n; j++){
            y += w[j];
        }
        diff = min(diff, abs(x-y));
    }
    cout << diff << endl;
    return 0;
}   