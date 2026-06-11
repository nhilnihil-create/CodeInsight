#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll = int64_t;

using namespace std;

ll n,m;
ll a[100010];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    REP(i,n)cin >> a[i];

    int two = 0;
    REP(i,n){
        if(i == 0){
            ll x = a[i];
            while(x % 2 == 0){
                two++;
                x /= 2;
            }
        }else{
            ll x = a[i];
            int y = 0;
            while(x % 2 == 0){
                y++;
                x /= 2;
            }
            if(y != two){
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    if(two != 0){
        REP(i,n) a[i] /= 2;
    }
    ll L = 1;
    REP(i,n){
        L = (L * a[i]) / gcd(L,a[i]);
    }
    
    cout << (1 + m/L)/2 << '\n';
    
}

