#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long int ull;
const int MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=1e9;

int main(){
    ll n;cin>>n;
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=n/10;
  n/=10;
    while(n>0){
        ans+=n/5;
        n/=5;
    }
    cout<<ans<<endl;
    return 0;
}