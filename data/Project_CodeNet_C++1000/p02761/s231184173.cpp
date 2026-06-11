#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main(){
    int n, m ;
    cin >> n >> m ;
    map<int, int> mp ;
    rep(i, m){
        int s, c ;
        cin >> s >> c ;
        if(mp.count(s)){
            if(mp[s] != c){
                cout << - 1 << endl ;
                return 0 ;
            }
        }
        if(s == 1){
            if(c == 0 && n != 1){
                cout << -1 << endl ;
                return  0;
            }
        }
        mp[s] = c ;
    }
    vector<int> ans (n) ;
    for(int i = 1; i <= n ; i++){
        ans[i - 1] = mp[i] ;
    }
    if(ans[0] == 0){
        if(n != 1){
            ans[0] = 1 ;
        }
    }
    rep(i, n){
        cout << ans[i] ;
    }
    cout << endl ;
    return 0 ;
} 