#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const ll INF = 1001001001;
const ll LINF = 1001001001001001001;

void prvec(vector<ll> vec){
    ll n = vec.size();
    rep(i,n) cout << i << " " << vec.at(i) << "\n";
}

void pr2d(vector<vector<ll>> vvec){
    ll h = vvec.size();
    ll w = vvec.at(0).size();
    rep(i,h){
        rep(j,w){
            cout << vvec.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}

ll n , k , sum;
vector<ll> a;

ll times(ll x){ //xが作りたい長さ
    ll ret = 0;
    rep(i,n){
        ret += a.at(i)/x;
        if(a.at(i)%x==0) ret--;
    }
    return ret;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    sum = 0;
    rep(i,n){
        cin >> a.at(i);
        sum += a.at(i);
    }
    sort(a.begin(),a.end());

    ll left = 1, right = a.at(n-1); //left=1を作るために必要なcut回数がsat rightを作るために必要な回数は0

    ll sat = sum - n;
    if(k>=sat){
        cout << 1 << endl;
        return 0;
    }else if(k==0){
        cout << a.at(n-1) << endl;
        return 0;
    }

    //xを作るために必要なcut回数を計算し、Kとの大小を比較する
    ll c = (left+right)/2;
    while(right-left>1){
        if(times(c)>k){
            left = c;
        }else{
            right = c;
        }
        c = (left+right)/2;
      	//cout << left << " " << c << " " << right << endl;
    }

    cout << right << endl;
	return 0;
}