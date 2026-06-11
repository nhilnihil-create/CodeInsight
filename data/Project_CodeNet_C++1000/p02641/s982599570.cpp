#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int x , n;
    cin >> x >> n;
    vector<int> a(200,0);
    if(n == 0){
        cout << x << endl; 
        return 0;
    } 
    for(int i = 1; i <= n; ++i){
        int p;
        cin >> p;
        a[p + 100] = 1;
    }

    if(a[x + 100] != 1){
         cout << x << endl;
         return 0;
    }

    for(int i = 1; i <= 100; ++i){
        int l = x + 100 - i;
        int r = x + 100 + i;
        if(a[l] != 1){
            cout << l - 100 << endl;
            return 0;
        }
        if(a[r] != 1){
            cout << r - 100 << endl;
            return 0;
        }
    }
    return 0;
}