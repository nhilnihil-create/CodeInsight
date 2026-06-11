#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

void solve(int n){
    int m=2*n+5;
    vector<int> isprime(m,1);
    isprime[0]=isprime[1]=false;
    int ans=0;
    rep(i,m){
        if(!isprime[i])continue;
        if(i>n&&i<=2*n)++ans;
        for(int j=2*i;j<m;j+=i)isprime[j]=false;
    }
    cout<<ans<<endl;
}
int main(){
    int n;
    while(cin>>n,n!=0)solve(n);
    return 0;
}
