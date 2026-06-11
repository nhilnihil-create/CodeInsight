#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n;
    cin >> n;
    bool flag = false;
    rep2(i, 1, 500000) {
        if(floor(i * 1.08) == n) {
            cout << i << endl;
            flag = true;
            break;
        }
    }
    if(!flag)
        cout << ":(" << endl;
    return 0;
}