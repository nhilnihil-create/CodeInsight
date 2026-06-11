#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18

int main() {
    int n ;
    cin >> n ;
    string s ;
    cin  >> s ;
    int res = 1 ;
    char t = s[0] ;
    rep(i, n){
        if(s[i] == t){
            continue ;
        }
        else {
            t = s[i] ;
            res++ ;
        }
    }
    cout << res << endl ;
}