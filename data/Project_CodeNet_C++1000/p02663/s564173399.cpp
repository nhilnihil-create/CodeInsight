#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <climits>
#include <map>
#include <unordered_map>
#define _USE_MATH_DEFINES
#include <cmath>
#include <set>
#include <unordered_set>
#include <iterator>
#include <deque>
#include <assert.h>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ull min(ull x, ull y){ if (x<y) return x; return y;}
ull max(ull x, ull y){ if (x<y) return y; return x;}
ll min(ll x, ll y){ if (x<y) return x; return y;}
ll max(ll x, ll y){ if (x<y) return y; return x;}
double min(double x, double y){ if (x<y) return x; return y;}
double max(double x, double y){ if (x<y) return y; return x;}
ull gcd(ull x, ull y){
    if (!x) return y;
    if (!y) return x;
    if (x>y) swap(x,y);
    return gcd(x, y%x);
}
ull inv(ull a, ull c){ // a,c are coprime and a<c
    if (a==1){
        return 1;
    }
    return ((c-(c/a))*inv(c%a,c))%c;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int h1, m1, h2, m2, k;
    cin>>h1>>m1>>h2>>m2>>k;
    int t1 = h1*60 + m1, t2 = h2*60+m2;

    int ans = max(0, t2-k-t1);

    cout<<ans<<"\n";

    return 0;
}




