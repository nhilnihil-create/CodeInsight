#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

//オーバフローしないようにかける順番を気を付ける
ll lcm(ll x,ll y){
    return ll(x/gcd(x,y))*y;
}

int		main(void)
{
	ll a, b;
	cin >> a >> b;

	if (a > b)
		cout << lcm(a, b) << endl;
	else
		cout << lcm(b, a) << endl;
}

