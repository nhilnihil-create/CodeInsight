#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)//rep(i,回数){処理}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int k,x;
    cin >> k >> x;
    if (500*k < x){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}