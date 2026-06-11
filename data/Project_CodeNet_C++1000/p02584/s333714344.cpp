#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long x,k,d; cin >> x >> k >> d;
    x = (long long)abs(x);
	long long tmp = min(k, x / d);
	k -= tmp, x -= tmp * d;
	if (k % 2)x -= d;
    cout << (long long)abs(x) << endl;
    return 0;
}
