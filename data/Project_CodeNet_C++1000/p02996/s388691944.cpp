#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
int n; cin>>n;
ll a[n],b[n];
pair<ll,ll> p[n];
rep(i,n){
    cin>>a[i]>>b[i];
    p[i] = make_pair(b[i],a[i]);
}
sort(p,p+n);
ll sum = 0;
rep(i,n){
sum += p[i].second;
if(sum > p[i].first){
    cout<<"No"<<endl;
    return 0;
}
}

cout<<"Yes"<<endl;
    return 0;
}
