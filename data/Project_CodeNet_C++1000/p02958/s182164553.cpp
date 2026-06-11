#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    rep(i, n){
        cin >> p[i];
        a[i] = p[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    rep(i,n){
        if(p[i] != a[i]){
            cnt++;
        }
    }
    if(cnt == 2 || cnt == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}