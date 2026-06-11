#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != i + 1) k++;
    }
    if(k <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}