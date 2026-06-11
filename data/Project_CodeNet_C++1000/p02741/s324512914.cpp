#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
#define REPR(i,n) for(int i = n; i >= 0; i--)
#define FOR(i,m, n) for(int i = m-1; i < n; i++)
#define INF 2000000000
#define ALL(v) v.begin(), v.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))
#define FILL2D(A,c) fill(A[0], A[0] +sizeof(A)/sizeof(**A),c)
#define FILL3D(A,c) fill(A[0][0], A[0][0] +sizeof(A)/sizeof(***A),c)
//vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))
//vector<intなど> 変数名(要素数,初期値)
using namespace std;
typedef long long ll;
//gcd,lcmセット
ll gcd(ll a, ll b){
   if (a%b == 0) return b;
   else return gcd(b, a%b);
}
ll lcm(ll a, ll b){	
   return a*b/gcd(a, b);
}
bool isPrime(ll x){
    int i;
    if(x < 2)return false;
    else if(x == 2) return true;
    if(x%2 == 0) return false;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return false;
    return true;
}
//dfsではvector<vector<int>> g(n);で◎
int main(){
    int k;
    cin>>k;
    int a[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cout<<a[k-1]<<endl;
}