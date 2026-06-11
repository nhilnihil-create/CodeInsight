#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
int n ;
string s ;

bool find (string t){
    char b = t[0] ;
    int r = 0 ;
    rep(i, n){
        if(s[i] == b && r == 2){
            r++ ;
            break ;
        }
        if(s[i] == b){
            r++ ;
            b = t[r] ;
        }
    }
    return r == 3 ;
}
int main() {
    cin >> n ;
    cin >> s ;
    int ans = 0 ;
    for(int i = 0; i <= 999 ; i++){
        string k = to_string(i) ;
        if(k.size() == 2){
            k = "0" + k ;
        }
        if(k.size() == 1){
            k = "00" + k ; 
        }
        if(find(k)){
            ans++ ;
        }
    }
    cout << ans << endl ;
} 