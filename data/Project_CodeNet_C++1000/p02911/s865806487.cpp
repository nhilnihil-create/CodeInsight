#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)

int main() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> points(n,k-q);
    rep(i,q){
        int a;
        cin >> a;
        a--;
        points[a]++;
    }
    rep(i,n){
        if(points[i]>0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}