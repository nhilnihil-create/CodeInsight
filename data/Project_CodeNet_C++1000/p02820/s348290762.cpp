#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int r, p, s; 
int c (char x){
    if(x == 'r') return p ;
    if(x == 's') return r ;
    if(x == 'p') return s ;
}
char f (char x){
    if(x == 'r') return 'p' ;
    if(x == 's') return 'r' ;
    if(x == 'p') return 's' ;
}
char find(char x, char y){
    if((x == 'r' && y == 's') ||(x == 's' && y == 'r')) return 'p' ;
    if((x == 'p' && y == 's') ||(x == 's' && y == 'p')) return 'r' ;
    if((x == 'r' && y == 'p') ||(x == 'p' && y == 'r')) return 's' ;

}
int main() {
    int n, k ; 
    cin >> n >> k ;
    cin >> r >> s >> p ;
    string t ;
    cin >> t ; 
    ll ans = 0 ;
    vector<char> vec(n) ;
    rep(i, n){
        if(i - k >= 0  && f(t[i]) == vec[i - k]){
            if(i + k > n || f(t[i + k]) == vec[i - k]) vec[i] = t[i] ;
            else {
                vec[i] = find(f(t[i + k]), vec[i - k]) ; 
            }
        }
        else{
            vec[i] = f(t[i]) ;
            ans += c(t[i]) ;
        }
    }
    cout << ans << endl ;
}  