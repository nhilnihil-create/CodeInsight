#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define F first
#define S second
#define ll long long
const int MOD = 1e9 + 7;
const float epsilon = 0.0005f;
const float PI = 3.1415926535897932384626433f;
 
vector<pair<int,int>> dire{{0,1},{0,-1},{1,0},{-1,0}};
 
// std::cout << std::fixed;
// std::cout << std::setprecision(9);

void solve(){
    int d, t, s;
    cin >> d >> t >> s;
    double ttake = (double)d / (double)s;
    if(ttake>t){
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // int t;cin>>t;
    // for(int i = 0;i<t;++i){
    //     solve();
    // }
    solve();
    return(0);
}