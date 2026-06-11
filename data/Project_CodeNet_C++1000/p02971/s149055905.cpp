#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 

int main() {
    int n ;
    cin >> n ;
    vector<int>  a (n);
    int mx ; 
    rep(i, n){
        cin >> a[i] ;
    }
    vector<int> b = a ; 
    sort(b.begin(), b.end()) ;
    int n1 = b[n - 1] ;
    int n2 = b[n - 2] ;
    rep(i, n){
        if(a[i] == n1){
            cout << n2 << endl ;
        }
        else {
            cout << n1 << endl ; 
        }
    }
}