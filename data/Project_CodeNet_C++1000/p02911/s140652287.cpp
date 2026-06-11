#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n, k);

    rep(i, q) {
        int p;
        cin >> p;
        a[p-1]++;
    }

    rep(i, n) {
        a[i] -= q;
        if(a[i] > 0) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }



    return 0;
}