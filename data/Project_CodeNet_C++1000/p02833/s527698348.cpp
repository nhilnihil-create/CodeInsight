//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

void start() {
	#ifndef ONLINE_JUDGE 
		freopen("in", "r", stdin); 
		freopen("out", "w", stdout); 
	#endif
}

int n, m;

int32_t main() {
    IOS;
    start();

    int n;
    cin >> n;
    if(n % 2 == 1) {
        return cout<< 0, 0;
    }
    n /= 2;
    int ans = 0;
    int cur = 5;
    while(true) {
        int val = n / cur;
        if(!val)
            break;
        ans += val;
        cur *= 5l;
    }
    print(ans);
}   