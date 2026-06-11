#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long MOD = 1000000007;

void Crack() {
	long long x,k,d;
    cin >> x >> k >> d;
    x = abs(x);
    long long cnt = 0,p = x/d;
    long long ans = 0;
    if(k<=p) ans = x - k*d;
    else {
        ans = x - p*d;
        k = k - p;
        if(ans>abs(ans-d)) {
            k--;
            ans = abs(ans-d);
        }
        if(k%2==1) ans = min(ans-d,min(ans,ans+d));
    }
    cout << abs(ans) << endl;
}

int main() {
	Boost;
    Crack();
	return 0;
}