#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
int main(){
    int h, w, n;
    cin >> h >> w >> n;
    cout << n / max(h, w) + ((n % max(h, w) == 0)?0:1) << endl;
    return 0;
}