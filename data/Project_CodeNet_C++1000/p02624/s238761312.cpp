#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};
std::vector<ll> IsPrime;

void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,-1); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]==-1) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j){
                if(IsPrime[i*j]==-1)
                    IsPrime[i*j] = i;
            } // (max以下の)iの倍数は
                      // 素数ではない
}

int main() {
    
    ll N;
    cin >>N;
    sieve(N+1);
    vector<ll> di(N+1);
    ll ans=0;
    di[1]=1;
    ans += 1;
    rep3(i,2,N+1){
        ll IP = IsPrime[i];
        if(IP==-1){
            di[i]=2;
        }else{
            ll now = i; 
            ll cnt = 0;
            while(1){
                if(now%IP == 0){
                    now/=IP;
                    cnt++;
                }else{
                    break;
                }
                
            }

            di[i]= di[i/IP]+(di[i/IP])/(cnt);
        }
    //cout<<i<<" "<<di[i]<<" "<<IP<<endl;
        ans +=i*di[i];
    }
    cout << ans << endl;


    return 0;
    

}