#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int a, b, c;
    cin >> a >> b >> c ;
    if( c - (a - b) < 0 ){
        cout << 0 << endl ;
    }
    else {
        cout <<  c - (a - b)  << endl ;
    }
} 
