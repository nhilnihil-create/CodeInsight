#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include<set>
#include<map>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define grt() greater<int>()
#define grtl() greater<long long>()

int main() {
    int n;
    cin >> n;
    vector<int> a(n-1);
    set<int> as;
    rep(i, n-1)
    {
        cin >> a[i];
        as.insert(a[i]);
    }

    sort(all(a));
    map<int, int> am;
    for (auto i = as.begin(); i != as.end(); i++)
    {
        int num = upper_bound(all(a), *i) - lower_bound(all(a), *i);
        am.insert(make_pair(*i, num));
    }

    rep(i, n) {
        cout << am[i + 1] << "\n";
    }

}