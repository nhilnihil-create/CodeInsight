#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> A(n,0);
    rep(i,q){
        int a;
        cin >> a;
        a--;
        A.at(a)++;
    }
    rep(i,n){
        if(k-q+A.at(i)>0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}