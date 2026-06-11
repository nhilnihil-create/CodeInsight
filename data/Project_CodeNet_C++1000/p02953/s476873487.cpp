#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    for(int i = n-1;i >= 1;i--){
        if(h.at(i) < h.at(i-1) - 1) {
            cout << "No" << endl;
            return 0;
        }else if(h.at(i) == h.at(i-1) - 1){
            h.at(i-1)--;
        }
    }
    cout << "Yes" << endl;
}