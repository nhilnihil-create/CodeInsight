#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    int n ;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        string s = to_string(i) ;
        if(s.size()%2==1){
            ans++ ;
        }
    }
    cout << ans << endl ;
} 
