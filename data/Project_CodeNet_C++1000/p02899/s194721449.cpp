#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int, int> a;

    rep(i, n){
        int ai;
        cin >> ai;
        a[ai] = i+1;
    }

    rep(i, n){
        cout << a.at(i+1);
        if(i<n-1) cout << ' ';
    }
    cout << "\n";
    return 0;
}