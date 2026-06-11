#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define REP(i,a,b) for(int i=a; i<=int(b); i++)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll l,r,d;
    cin >> l >> r >> d;
    cout << int(r/d)-int(l/d)+(l%d==0);
    return 0;
}
