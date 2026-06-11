#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    for(auto x : a){
        if(x % 2 == 0){
            if(x % 3 != 0 && x % 5 != 0){
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
}