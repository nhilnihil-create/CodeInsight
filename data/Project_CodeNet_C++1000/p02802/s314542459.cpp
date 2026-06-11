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
    int ans = 0 ;
    int pen = 0 ;
    vector<vector<string>> str(n) ;
    rep(i, m){
        int p ;
        string s ;
        cin >> p >> s ;
        p-- ;
        str[p].push_back(s) ;
    }
    rep(i, n){
        int f  = str[i].size() ;
        rep(j, f){
            if(str[i][j] == "WA") {
                pen++ ;
            }
            else if (str[i][j] == "AC"){
                ans++ ;
                break ;
            }
            if(j == f - 1){
                pen -= f ;
            }
        }
    }
    cout << ans << " " << pen << endl ;
} 