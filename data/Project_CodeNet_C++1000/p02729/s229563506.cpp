
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;



int main(){
    int n, m;
    cin >> n >> m;
    int ans=0;
    ans += n*(n-1)/2;
    ans += m*(m-1)/2;
    cout << ans << endl;

   

}