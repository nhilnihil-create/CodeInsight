#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int a, b;
    cin >> a >> b;
    int x = max(a,b);
    int y = min(a,b);
    
    REP(i,x) cout << y;
    cout << endl;
}