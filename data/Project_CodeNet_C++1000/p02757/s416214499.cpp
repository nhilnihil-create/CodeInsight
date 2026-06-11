#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} //配列vにn個の要素を入力する
#define rep(i, l, n) for (int i = l; i < (int)(n); i++)
#define repn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 

const int mod = 1000000007;
const int inf = 1e9;

int main(){
    int n, p;
    string s;
    cin >> n >> p >> s;
    if(p==2||p==5){
        ll ans = 0;
        rep(i,0,n){
            if((s[i]-'0')%p==0)ans+=i+1;
        }
        cout << ans;
        return 0;
    }

    vi d(n+1);//累積和
    d[0] = 0;
    ll ten = 1;
    for(int i = 0 ; i < n ; i++){
        d[i+1] = (d[i]+(s[n-1-i]-'0') * ten) % p;
        ten *= 10;
        ten %= p;
    }  //d[i]にi桁まで合計した累積和をpで割った余りが入っている
    vector<ll> r(p);
    ll ans = 0;
    for(int i = 0 ; i <= n ; i++){
        r[d[i]]++;
    }
    for(int i = 0 ; i < p ; i++){
        ans += r[i]*(r[i]-1)/2;
    }
    cout << ans << endl;

}