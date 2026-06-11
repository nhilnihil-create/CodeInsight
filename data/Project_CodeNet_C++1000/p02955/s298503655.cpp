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


template <typename T> vector<T> divisor(T a) {
    vector<T> res;
    for (T i = 1; i*i <= a; i++) {
        if(a%i == 0){
            res.push_back(i);
            if(i != a/i) res.push_back(a/i);
        }
    }
    return res;
}


int main()
{
    int N,K;
    cin >> N >> K;
    vi A(N);
    in(N,A);
    int sum = 0;
    rep(i,N) sum += A[i];
    vi B = divisor(sum);
    sort(all(B));
    reverse(all(B));
    //outve(B);
    
    rep(i,int(B.size())) {
        vi C;
        rep(j,N) C.pb(A[j]%B[i]);
        sort(all(C));
        //outve(C);
        vi Csum(N+1);
        Csum[0] = 0;
        reps(j,1,N+1) Csum[j] = Csum[j-1]+C[j-1];
    
        rep(j,N+1){
            ll a = (ll)B[i]*(ll)(N-j)-(ll)(Csum[N]-Csum[j]);
            
            if(abs((ll)Csum[j]-a) % (ll)B[i] == 0){
                if(Csum[j] <= K && a <= K){
                    cout << B[i] << endl;
                    return 0;
                }
            }
        }
        
    }
    
    
    return 0;
}
