#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int half = n/2-1;
    // cout << half << a.at(half) << a.at(half+1) << endl;
    if(a.at(half)==a.at(half+1)) cout << 0 << endl;
    else cout << a.at(half+1) - a.at(half) << endl;
    return 0;
}