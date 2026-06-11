#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
#define MP make_pair
#define INF (sizeof(int) == 4 ? 1e9:1e18)
#define EPS 0.0000000001
using namespace std;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<typename Head, typename Value> auto vectors(const Head &head, const Value &v) { return vector<Value>(head, v); }
template<typename Head, typename... Tail> auto vectors(Head x, Tail... tail) { auto inner = vectors(tail...); return vector<decltype(inner)>(x, inner); }
template<class T> void join(T a){int b=0;for(auto itr :a){if(b++!=0)cout << " "; cout << itr;} }
using ll  = long long;
using ld  = long double;
using pii = pair<int,int>;
using piii = pair<int,pii>;
int W,H;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool valid(int x,int y){return (0<=x&&x<W)&&(0<=y&&y<H);}
#define int ll
class Prime{
public:
    vector<bool>Isprime;
    vector<int>prime;
    int size;
    Prime(int n) : Isprime(n+1,true),size(n+1){
        Isprime[0] = Isprime[1] = false;
        for(int i = 2; i<=size; i++){
            if(!Isprime[i])continue;
            prime.push_back(i);
            for(int j = 2;i*j <=size;j++) Isprime[i*j] = false;
        }
    }
    bool IsPrime(int n){return (n<=size? Isprime[n]:false);}
    int indexOf(int i){return (i<prime.size()?prime[i]:INF);}
};
signed main(){
    Prime p(123456*5);
    int n;
    while(cin >> n, n){
        int cnt = 0;
        for(int i = 0; i< p.prime.size();i++)
            if(n+1 <= p.prime[i] && p.prime[i] <=2*n)cnt++;
        cout << cnt << endl;
    }
}


