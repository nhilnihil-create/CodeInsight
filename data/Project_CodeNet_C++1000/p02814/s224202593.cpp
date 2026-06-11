#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N,M;
    cin >>N>>M;
    vector<ll> a(N);
    bool flag = 0;
    rep(i,N){
        cin >> a[i];
    }
    ll pcnt;
    rep(i,N){
        ll cnt = 0;
        
        ll  now =a[i];
        
        while((now%2)==0){
            cnt++;
            now /=2;
        }
        if(cnt != pcnt && i != 0){
            flag = 1;
            break;
        }
        pcnt = cnt;
    }
    ll ans;
    if(flag == 0){
        ll LCM;
        if(N==1){
            LCM = a[0]/2;
        }else{
            LCM = lcm(a[0]/2,a[1]/2);
        }
        for(ll i = 2; i<N;i++){
            LCM = lcm(LCM,a[i]/2);
        }
        
     
            ans = (M/LCM+1)/2;

    }else{
        ans = 0;
    }
    
    cout << ans << endl;


    return 0;
    

}