#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    int total = 0;
    rep(i, n)rep(j, n){
        if(i != j){
            int rec = d[i] * d[j];            
            total += rec;
        }
    }
    cout << total / 2 << endl;
    return 0;
}