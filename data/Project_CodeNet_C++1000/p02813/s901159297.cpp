#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main(){
    int n ;
    cin >> n ;
    vector<int> p (n) ;
    vector<int> q (n) ;
    rep(i, n) cin >> p[i] ;
    rep(j, n) cin >> q[j] ;
    vector<int> v (n) ;
    int a = 0 ;
    int b = 0 ;
    rep(i, n){
        v[i] = i + 1 ;
    }
    int num = 1 ;
    do{
        if(p == v){
            a = num ;
        }
        if(q == v){
            b = num ;
        }
        if(a != 0 && b != 0){
            break; 
        }
        num++ ; 
    }while(next_permutation(v.begin(),v.end())) ;
    cout << abs(a - b) << endl ; 

} 