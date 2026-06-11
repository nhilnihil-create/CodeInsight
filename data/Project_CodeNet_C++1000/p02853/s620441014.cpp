#include <bits/stdc++.h>
#define rep(i,n)  for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define deb(x) cerr << #x <<": " << x << '\n';
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
typedef long double ld;
typedef long long ll;

int main(){
    ios;
    int x, y; cin >> x >> y;
    int sum = 0;
    if(x == 1 && y == 1) sum += 400000;
    
    if(x == 3) sum += 100000;
    if(x == 2) sum += 200000;
    if(x == 1) sum += 300000;
    
    if(y == 3) sum += 100000;
    if(y == 2) sum += 200000;
    if(y == 1) sum += 300000;
    cout << sum;
    return 0;
}
