#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;


ll dvceil(ll x, ll y) {
    return (x+y-1)/y;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int m;
    cin>>m;
    ll sum = 0;
    ll cnt = 0;
	
    while (m--) {
	ll d, c;
	cin>>d>>c;
	sum += d*c;
	cnt += c;
    }


    ll res = (cnt-1) + dvceil(sum-9,9);
    cout<<res<<endl;    
    
    return 0;
}
