#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005
    ll a[MAX_N];
    ll b[MAX_N];

int main() {
    ll n;
    cin >> n;
    
    rep(i,n){cin >> a[i];}
    rep(i,n){cin >> b[i];}

    ll i = n;
    ll ans = 0;


    while(true){
        if(b[i%n] == a[i%n]){
            i++;
        }else if(b[i%n] < a[i%n]){
            cout << "-1" << endl;
            return 0;
        }else if((b[(i-1)%n] < b[i%n]) && (b[i%n] > b[(i+1)%n])){
            ll count = (b[i%n] - a[i%n]) / (b[(i-1)%n] + b[(i+1)%n]);
            if(count == 0){
                cout << "-1" << endl;
                return 0;
            }
            b[i%n] -= (b[(i-1)%n] + b[(i+1)%n]) * count;
            ans += count;
            i++;
            /*
            rep(j,n){
                cout << b[j] << ' ';
            }
            cout << ans << endl;
            */
        }else if(b[i%n] == b[(i+1)%n]){
            cout << "-1" << endl;
            return 0;
        }else{
            i++;
        }

        if(i % (n*2) == 0){
            int flag = 0;
            rep(j,n){
                if(a[j] != b[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
            //cout << i;
        }
    }

    cout << ans << endl;
    return 0;
}
 
 
