#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

int const MAX_N = 100000;
vector<ll> prime;
vector<bool> is_prime(MAX_N,true);
void Eratosthenes() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2;i*i < MAX_N;++i) if (is_prime[i]) for (ll j = 2*i;j < MAX_N;j += i) is_prime[j] = false;
    for (ll i = 0;i < MAX_N;++i) if (is_prime[i]) prime.push_back(i);
}

vector<pair<ll,int>> prime_factorization(ll a) {
    vector<pair<ll,int>> prime_factor;
    if (is_prime[0]) Eratosthenes();
    for (ll& i : prime) {
        if (i*i > a) break;
        if (a%i == 0) {
            P p = P(i,0);
            while (a%i == 0) {
                a /= i;
                p.second++;
            }
            prime_factor.push_back(p);
        }
    }
    if (a != 1) prime_factor.push_back(P(a,1));
    return prime_factor;
}

void rec(vector<ll>& div,vector<pair<ll,int>>& fact,int i,ll d) {
    if (i == fact.size()) {
        div.push_back(d);
        return;
    }
    for (int j = 0;j <= fact[i].second;++j) {
        rec(div,fact,i+1,d);
        d *= fact[i].first;
    }
}

vector<ll> divisor(ll a) {
    vector<ll> div;
    vector<pair<ll,int>> prime_factor = prime_factorization(a);
    rec(div,prime_factor,0,1);
    return div;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n;++i) cin >> a[i];
    ll sum = 0;
    for (int i = 0;i < n;++i) sum += a[i];
    vector<ll> div = divisor(sum);
    int ans = 1;
    for (int d : div) {
        vector<int> x,y;
        for (int i = 0;i < n;++i) if (a[i]%d) {
            x.push_back(a[i]%d);
            y.push_back(d-a[i]%d);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int s1 = 0,s2 = 0,m = x.size();
        for (int i = 0;i < m;++i) s2 += y[i];
        for (int i = 0;i < m;++i) {
            s1 += x[i];
            s2 -= y[m-1-i];
            if (s1 == s2) {
                if (s1 <= k) ans = max(ans,d);
                break;
            }
        }
    }
    cout << ans << endl;
}