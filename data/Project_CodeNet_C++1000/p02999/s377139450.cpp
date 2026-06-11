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
    int x,a;
    cin>>x>>a;
    if(x<a) cout<<"0"<<endl;
    else cout<<"10"<<endl;
    return 0;
}