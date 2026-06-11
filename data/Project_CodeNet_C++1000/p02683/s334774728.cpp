#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
long long MOD = 1000000007;


template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
long long lcm (int a, int b){
    return  (long long) a*b /gcd(a,b);
}

long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }


int main(){
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>>a(n,vector<int>(m));
    vector<int> c(n);

    rep(i,n){
        cin >> c[i];
        for(int j = 0; j<m; j++)cin >> a[i][j];
    }
    int ans = 12345678;
    int all = 1<<n;
    for(int mask = 0; mask < all ; mask++){
        vector<int> level(m);
        int cost =0;
        for(int i = 0; i< n; i++){
            if((mask >> i)&1){
                cost += c[i];
                for(int j = 0; j<m; j++){
                    level[j] += a[i][j];
                }
            }
        }
        bool ok = true;
        for (int j =0; j< m; j++){
            if(level[j] < x)ok = false;
        }
        if(ok)ans = min(ans,cost);
    }
    if(ans == 12345678)cout << -1 << endl;
    else cout << ans << endl;

}

