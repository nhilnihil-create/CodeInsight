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

int main () {
    ll  a, b, c ;
    cin >> a >> b >> c ; 
    ll d = c - a - b ;
    if(d > 0 && d * d > 4 * a * b){
        cout << "Yes" << endl ; 
    }
    else {
        cout << "No" << endl ; 
    }
}

