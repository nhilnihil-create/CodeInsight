#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
//#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N = 900000;
const int K = 60;
const int mod = 1e9 + 7;
map < int, int > mp;
int a[N], cnt[N];
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    set < int > s;
    for (int i = 0; i < (1 << n); i++){
        cin >> a[i];
        s.insert(-a[i]);
    }
    int c = 0;
    for (auto i: s){
        mp[-i] = c;
        c++;
    }
    for (int i = 0; i < (1 << n); i++){
        a[i] = mp[a[i]];
        cnt[a[i]]++;
    }
    multiset < int > q;
    if (cnt[0] != 1){
        cout << "No";
        return 0;
    }
    q.insert(-n);
    for (int i = 1; i < c; i++){
        int x = cnt[i];
        vector < int > b;
        b.clear();
        while(!q.empty() && x > 0){
            int y = -(*q.begin());
            q.erase(q.begin());
            if (y > 1) b.pb(y - 1);
            x--;
            y--;
            if (y != 0) q.insert(-y);
        }
        if (x != 0 && q.size() == 0){
            cout << "No";
            return 0;
        }
        for (auto j: b) q.insert(-j);
    }
    cout << "Yes";
}
