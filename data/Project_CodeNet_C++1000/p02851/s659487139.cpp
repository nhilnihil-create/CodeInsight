#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
#define INF 1000000000
const int MAX = 1000000;
const int MOD = 1000000007;


int main(){
	int n,k;
    cin>>n>>k;
    vector<ll> s(n+1);
    s[0]=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s[i+1]=s[i]+t;
    }
    REP(i,n+1){
        s[i]=(s[i]-i)%k;
    }
    ll ans=0;
    map<int,int> m;
        for(int i=0;i<min(n+1,k);i++){
            m[s[i]]++;
        }
        for(int i=0;i<n+1;i++){
            ans+=m[s[i]]-1;
            if(i+k<=n) m[s[i+k]]++;
            m[s[i]]--;
        }
    OUT(ans);
	return 0;
}