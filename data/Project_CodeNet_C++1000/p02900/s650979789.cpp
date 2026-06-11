#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

ll gcd(ll x, ll y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}

//gcd(A, B)の約数（＝A, Bの公約数）を求める関数
//求めた公約数は、vector<pair<ll, int>>型配列に入れられる。(firstが公約数の値、secondが出現回数)
vector<pair<ll, int>> factorize(ll n){
    vector<pair<ll, int>> p;
    //Nの約数を求める時は、約数の候補は、1~sqrt(N)までを見ればよいことから、このようにする
    //今回は1はmain関数内のarray.size()+1の+1で補っている
    for(ll i = 2; i*i < n; i++){
        if(n % i != 0) continue;
        p.emplace_back(i, 0);
        //iで何回割れるかを求める
        while(n % i == 0){
            n /= i;
            p.back().second++;
        }
    }
    if(n != 1) p.emplace_back(n, 1);
    return p;
}

int main(){
    ll A, B;
    cin >> A >> B;
    ll g = gcd(A, B);
    auto array = factorize(g);
    ll ans = array.size() + 1;
    cout << ans << endl;
    return 0;
}