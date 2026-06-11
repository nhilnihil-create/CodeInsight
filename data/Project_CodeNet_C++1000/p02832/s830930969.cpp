#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = n;
    int j = 1;
    rep(i,n) {
        if(a[i] == j) {
            --ans;
            ++j;
        }
    }
    if(j == 1) ans = -1;
    cout<< ans << endl;

    return 0;
}
