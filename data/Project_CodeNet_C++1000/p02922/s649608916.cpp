#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int a, b ;
    cin >> a >> b ;
    int n = 1;
    int t = a;
    while(b > t){
        n++ ; 
        t = t + a - 1 ;
    }
    if(b == 1){
        n = 0 ;
    }
    cout << n << endl ;
}