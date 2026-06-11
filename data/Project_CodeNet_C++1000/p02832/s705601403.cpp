#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n;
    cin >> n;
    int now = 1;
    int ans = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a==now){
            ans++;
            now++;
        }
    }
    if(ans == 0)
        cout << -1 << endl;
    else
        cout << n-ans << endl;
    return 0;
}