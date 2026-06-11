#include<bits/stdc++.h>
#include<cstring>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int           long long
#define umapii        unordered_map<int,int>
#define ps(x,y)       fixed<<setprecision(y)<<x // sets precision upto required digits
#define arr(a,n)      int n;cin>>n;int a[n];for(int i=0;i<n;i++){cin>>a[i];}
#define outarr(a,n)   for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define mod           1000000007
#define ff            first
#define big           1e15
#define ss            second
#define add           push_back
#define remove        pop_back
#define mapii         map<int,int>
#define large         *max_element
#define small         *min_element
#define float         double
#define pqi           priority_queue<int>
#define mpqi          priority_queue<int,vector<int>,greater<int>>
#define in(n)         int n;cin>>n;
#define w(t)          int t;cin>>t;while(t--)
#define vi            vector<int>
#define vivi          vector<vector<int>>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>pbds;


int getprice(vivi a, int n, int m, int i, int x) {
    int k = 0;
    int price = 0;
    vi temp(m, 0);
    while (i > 0) {
        if (i & 1) {
            price += a[k][0];
            for (int j = 1; j <= m; j++) {
                temp[j - 1] += a[k][j];
            }
        }
        i = i >> 1;
        k++;
    }
    bool flag = true;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] < x) {
            flag = false;
            break;
        }
    }
    if (flag == false) {
        return -1;
    }
    return price;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);
#endif

    in(n); in(m); in(x);
    vivi v(n, vi(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < (1 << n); i++) {
        int price = getprice(v, n, m , i, x);
        if (price != -1) {
            ans = min(ans, price);
        }
    }
    if (ans == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }


}