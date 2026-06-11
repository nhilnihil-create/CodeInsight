#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 2005
#define INF 1000000005
#define INFLL (long long)1e18
#define PI 3.1415926535897
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    ll n;
    cin>>n;
    map<ll,int>m;
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            n/=i;
            m[i]++;
        }
    }
    if(n!=1)m[n]++;
    int a[20];
    REP(i,20){
        a[i]=i*(i+1)/2;
    }
    int ans=0;
    for(auto p:m){
        for(int i=19;i>=0;i--){
            if(a[i]<=p.second){
                ans+=i;
                break;
            }
        }
    }
    OUT(ans);
    return 0;
}
