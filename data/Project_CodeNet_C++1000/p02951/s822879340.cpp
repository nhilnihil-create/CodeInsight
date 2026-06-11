#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll choose2(ll n){
    return n*(n-1)/2;
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans = c - (a - b);
    if(ans <= 0) ans = 0;
    cout<<ans<<endl;
    return 0;
}