#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define int long long

using namespace std;
const int inf = 1e18;
const double EPS = 0.00000001;
const int mod = 1000000007;

signed main(){
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    for(int i =2;i<=1000000;i++){
        if(a%i == 0 && b%i == 0){
            cnt++;
        }
        while(a%i == 0) a/= i;
        while(b%i == 0) b/= i;
    }
    if(a == b && a > 1) cnt++;
    cout << cnt+1;
}
