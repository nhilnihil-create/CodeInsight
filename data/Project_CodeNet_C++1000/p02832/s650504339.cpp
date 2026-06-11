#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
    }
    int su = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == su) su++;
    }
    if(su == 1) cout << "-1" << endl;
    else cout << n-su+1 << endl;

    return 0;
}