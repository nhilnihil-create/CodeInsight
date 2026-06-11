#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main(){
    
    cout << fixed << setprecision(6);
    int n ;
    cin >> n;
    double ans ;
    if(n % 2 == 0){
        ans = 0.5;
    }
    else {
        int a = n / 2;
        ans = (double)(a + 1)/ n; 
    }
    cout << ans << endl;
}