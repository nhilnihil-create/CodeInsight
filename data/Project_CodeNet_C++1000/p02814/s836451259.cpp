#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long int;

const int N_MAX = 100005;
int n, m;
vector<ll> a;

template< typename T >
T extgcd(T a, T b, T &x, T &y) {
  T d = a;
  if(b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

int main(){
    cin >> n >> m;
    int e;
    bool ans = true;
    for(int i = 0; i < n; i++){
        ll ai;
        cin >> ai;
        a.push_back(ai);
        int num = 0;
        while(!(ai & 1)){
            ai = ai >> 1;
            num++;
        }
        if (i == 0)e = num;
        else{
            if (e != num)ans = false;
        }
    }
    if (!ans){
        cout << 0 << endl;
        return 0;
    }

    ll L = a[0];
    for(int i = 1; i < n; i++){
        ll x, y;
        if (L <= 2 * m){
            ll gcd = extgcd(L, a[i], x, y);
            L = L * a[i] / gcd;
        }
    }
    ll ansn = 0;
    ll now = L / 2;
    while(now <= m){
        ansn++;
        now += L;
    }
    cout << ansn << endl;
    return 0;
}