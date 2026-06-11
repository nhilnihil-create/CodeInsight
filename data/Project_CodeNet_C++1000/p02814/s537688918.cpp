#include <vector>
#include <list>
#include <map>
#include <unordered_set>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <tuple>
#include <set>
#include <iostream>
#define MAXX (1ll<<61)
#define MAX_CARRY 10
using namespace std;
#define ll long long

ll gcd(ll a, ll b) {
    while(b!=0) {
        ll t = b;
        b=a%b;
        a=t;
    }
    return a;
}

ll a[111111];


int main() {
    int N;
    cin>>N;
    ll M;
    cin>>M;
    ll L=1;
    for(int i=1;i<=N;i++) {
        ll A;
        cin>>A;
        A/=2;
        a[i]=A;
        // L*A[i] >= MAXX*G
        ll G = gcd(L,A);
        L = L*(A/G);
        L = min(L, M+1);
    }
    
    ll ans = ((M/L)+1)/2;
    
    for(int i=1;i<=N;i++) {
        if ((L / a[i])%2==0) {
            ans = 0;
        }
    }
    
    cout << ans << endl;

    return 0;

    
    // A[i]*(2*p+1)
    
}
