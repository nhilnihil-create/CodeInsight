#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<ll> score(n,k-q);
    vector<int> a(q);
    rep(i,q) {
        cin >> a[i];
        score[a[i]-1]++;
    }
    rep(i,n) {
        if(score[i] <= 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
