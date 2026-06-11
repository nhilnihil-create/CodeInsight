#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int h,n;
    cin >> h >> n;
    while(n-- > 0){
        int a;
        cin >> a;
        h -= a;
        if(h <= 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}