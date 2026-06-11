//----------------------------------------------------------------------
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//----------------------------------------------------------------------

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    rep(i, n)
        cin >> p[i];
    rep(i, n)
        cin >> q[i];

    vector<int> a(n);
    rep(i, n)
        a[i] = i + 1;


    int numa = 0;
    int numb = 0;
    int cnt = 0;
    do {
        cnt++;
        bool flag1 = true;
        bool flag2 = true;
        for(int i = 0; i < n; ++i) {
            if(a[i] != p[i]) {
                flag1 = false;
            }
            if(a[i] != q[i]) {
                flag2 = false;
            }
        }

        if(flag1) {
            numa = cnt;
        }
        if(flag2) {
            numb = cnt;
        }
    }while(next_permutation(a.begin(), a.end()));

    cout << abs(numa - numb) << endl;

    return 0;
}
