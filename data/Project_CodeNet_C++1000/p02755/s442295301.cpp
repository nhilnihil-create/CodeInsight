#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;

    for(int i=1; i<=1250; i++) {
        int ibuff1=i*0.08;
        int ibuff2=i*0.10;
        if (ibuff1==a && ibuff2==b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;

    return 0;
}