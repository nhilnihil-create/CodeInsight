#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define _dec(i,N,j) for(int i = (N-1);i >= (j);i--)
#define _rec(i,N,j) for(int i = (N);i >=(j);i--)
#define ALL(x) x.begin(),x.end()
#define MEM(a,n) memset(a,n,sizeof(a))
#define fst first
#define scd second
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int get_int(){int x;scanf("%d",&x);return x;}
LL get_ll(){LL x;scanf("%lld",&x);return x;}
double get_db(){double x;scanf("%lf",&x);return x;}

template<typename T> int chmin(T &a,T b){if(a > b){a = b;return 1;}else return 0;}
template<typename T> int chmax(T &a,T b){if(a < b){a = b;return 1;}else return 0;}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {_for(i,0,v.size()) os << v[i] << " ";return os;}
template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){for(auto a:v) os << a <<" ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){os << v.fst <<" "<<v.scd << " ";return os;}
template<typename T1,typename T2>
ostream& operator<<(ostream& os,const map<T1,T2>& v){for(auto a:v) cout << a << endl;return os;}

static const int dx[8] = { -1,  0, 1, 0,  1, -1,  1, -1};
static const int dy[8] = {0,  1, 0,  -1,  1, -1, -1,  1};
const double pi  = acos(-1.0);
const double eps = 1e-8;
const LL  INF  = 0x3f3f3f3f3f3f3f3f;
const int inf  = 0x3f3f3f3f;

const int maxn = 1e6+5;
const int maxp = 1005;

int is_pair = 1;
int is_set = 1;

int A[maxn];
int N;

map<int,int> mp;

int isprime[maxp],cnt,factor[maxp],facnum;
int primes[maxp];

void makeprimes(){
     _for(i,2,maxp){
        isprime[i] = 1;
    }
    _for(i,2,maxp){
        if(isprime[i]){
            for(int j = i+i;j < maxp;j += i){
                isprime[j] = 0;
            }
        }
    }
    cnt = 0;
    _for(i,2,maxp){
        if(isprime[i])
            primes[cnt++] = i;
    }
}

void fact(int n)
{
    int max_fac = sqrt(n+1);
	for(int i = 0; i < cnt; i++){
        if(primes[i] > max_fac) break;
        int c = 0;
        _for(j,0,N){
            if(A[j] % primes[i] == 0){
                c++;
                while(A[j] % primes[i] == 0) A[j] /= primes[i];
            }
        }

        if(c >= 2){
            is_pair = 0;
        }
        if(c == N){
            is_set = 0;
        }
        if(!is_pair && !is_set) return;
	}

    _for(i,0,N){
        if(A[i] != 1){
            mp[A[i]]++;
        }
    }
    for(auto a:mp){
        if(a.second >= 2) is_pair = 0;
        if(a.second == N) is_set = 0;
    }

}




int main()
{
    makeprimes();
    //cout << cnt << endl;

    cin >> N;

    _for(i,0,N){
        scanf("%d",&A[i]);
    }

    fact(maxn);

    if(is_pair){
        cout << "pairwise coprime" <<endl;
    }else if(is_set){
        cout << "setwise coprime" <<endl;
    }else{
        cout << "not coprime" <<endl;
    }

    return 0;
}
