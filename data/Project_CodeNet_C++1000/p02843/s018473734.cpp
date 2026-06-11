
// Problem : C - 100 to 105
// Contest : AtCoder - Sumitomo Mitsui Trust Bank Programming Contest 2019
// URL : https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Macros

#define ll long long
#define db long double
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mi map<int,int>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define inf 1e10
#define PI acos(-1.0)
#define int long long
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 100005

//Solution

void solve(){
    int n;
    cin>>n;
    for(int a=0;a<=1000;a++){
        if(a*100 > n) break;
        for(int b=0;b<=1000;b++){
            if(a*100+b*101 > n) break;
            for(int c=0;c<=1000;c++){
                if(a*100+b*101+c*102 > n) break;
                for(int d=0;d<=1000;d++){
                    if(a*100+b*101+c*102+d*103 > n) break;
                    for(int e=0;e<=1000;e++){
                        if(a*100+b*101+c*102+d*103+e*104 > n) break;
                        for(int f=0;f<=1000;f++){
                            if(a*100+b*101+c*102+d*103+e*104+f*105 > n) break;
                            if(a*100+b*101+c*102+d*103+e*104+f*105 == n){
                                cout<<1;
                                return;
                            }
                        }
                    }
                }
            } 
        }
    }
    cout<<0;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tests;
    //cin>>tests;
    tests = 1;
    while(tests--){
        solve();
    }
    return 0;
}