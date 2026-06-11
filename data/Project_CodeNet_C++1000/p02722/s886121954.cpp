#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int         ll
typedef vector<int> vi;
#define test        int t; cin >> t; while(t--)
#define max(a,b)   (a>b?a:b)
#define min(a,b)   (a<b?a:b)
const int mod = 1000000007;



int div(int n) {
    int re = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            re += 2;
            if (n / i == i) {
                re--;
            }
        }

    }
    return re;
}

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if(n==2){
        cout<<1;
        return 0;
    }
    int ans=2;

    for (int i = 2; i * i <= n; ++i) {

        int n1 = n;
        if ((n1-1) % i == 0) {
            if((n1-1)/i==i) ans++;
            else ans+=2;
        }else{
            while(!(n1%i)){
                n1/=i;
            }
            if(n1%i==1) ans++;
        }

    }

    cout<<ans;

    return 0;
}