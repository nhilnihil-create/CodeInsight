//Uneven Numbers
#include <bits/stdc++.h> //C++の機能を「全て」読み込むための命令
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<(x)<<endl
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll inf=1e18;
const int N=2e5+10;
ll factorial(ll x){//階乗の計算
    if(x==0||x==1) return 1;
    return x*factorial(x-1);
}
ll gcd(ll a ,ll b){return b ? gcd(b,a%b) : a;}//最大公約数
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}//最小公倍数
int num_digit(ll a){//桁数を求める
    int num_dig = 0;
    while(a!=0){
        a /= 10;
        ++num_dig;
    }
    return num_dig;
}
vector<ll> digit(ll a){//桁の数字を求める
    vector<ll> dig(num_digit(a));
    for(int i=num_digit(a)-1; i>=0; --i){
        dig[i] = a%10;
        a /= 10; 
    }
    return dig;
}

int main(){
    int n;
    cin >> n;

    vector<int> a = {9,0,900,0,90000};

    int keta = 0;
    int n_kari = n;
    while(n_kari!=0){
        n_kari /= 10;
        ++keta;
    }

    int sum=0;
    if(keta%2==0){
        rep(i,keta-1) sum += a[i];
    }
    if(keta%2!=0){
        sum += n - pow(10,keta-1) + 1;
        rep(i,keta-1) sum += a[i];
    }
    cout(sum);
    return 0;
}