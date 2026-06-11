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






int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output3.txt", "w", stdout);
#endif

    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            ans++;
        }
    }
    cout << ans << endl;

}
