#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    ll n;cin >> n;
    ll d = 1e9;
    ll y3 = (n/d)+(n%d > 0);
    ll x3 = d-(n%d);
    if(n%d==0) x3 = 0;
    //cout << n%d << endl;

    if(n < d) printf("0 0 %lld 0 %d %d\n",n,0,1);
    else if(n <= d*d) printf("%d %d %lld %d %lld %lld\n",0,0,d,1,x3,y3);
    
    
}