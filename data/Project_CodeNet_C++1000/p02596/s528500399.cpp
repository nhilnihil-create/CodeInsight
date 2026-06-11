#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    int a[2000100],k;
    cin >> k;
    
    a[1] = 7%k;
    for(int i=2;i<=k;i++) a[i] = (a[i-1]*10 + 7)%k;
    
    for(int i=1;i<=k;i++) if(a[i] == 0){
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}