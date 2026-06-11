#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 
int main(){
    int k, n ;
    cin >> k >> n ;
    vector<int> a (n) ;
    rep(i, n) cin >> a[i] ;
    vector<int> len (n) ;
    rep(i, n){
        if(i == n -1){
            len[i] = a[0] + (k - a[i]) ;
        }
        else {
            len[i] = a[i + 1] - a[i] ;
        }
    }
    sort(len.rbegin(), len.rend()) ;
    cout << k - len[0] << endl ;
} 