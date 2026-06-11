#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;




int main()
{

    int N;
    cin >> N;
    
    vl s = {1,10,10,4,10,10,4,10,10,2};
    vl a = {1,10,11,4,13,14,5,16,17,2};
    ll ans = 0;
    vi A;
    
    rep(i,N){
        int d,e;
        ll c;
        cin >> d >> c;
        if(d == 0) ans += c-1, e = d;
        else{
            while (c >= s[d]) {
                ll cc = c / s[d];
                ans += cc*a[d];
                c = c-cc*s[d]+cc;
            }
            e = d;
            while (c > 1) {
                c--;
                ans++;
                e += d;
                if(e/10 > 0){
                    ans++;
                    e = e%10 + e/10;
                }
            }
        }
        
        A.pb(e);
    }
    
    //outve(A);
    //cout << ans << endl;
    
    int sum = A[0];
    reps(i,1,A.size()){
        sum += A[i];
        ans++;
        if(sum/10 > 0){
            ans++;
            sum = sum/10+sum%10;
        }
    }
    
    cout << ans << endl;
    
    
    

    return 0;
}
