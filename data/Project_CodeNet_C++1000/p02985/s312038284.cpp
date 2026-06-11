#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100010
#define INF 10000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000000;
const int MOD = 1000000007;
vector<int> to[N];
int k;
ll ans=1;
void dfs(int no=0,int p=-1){
    if(-1==p){
        for(int i=k-1;i>=k-SZ(to[no]);i--){
            ans*=i;
            ans%=MOD;
        }
    }else{
        for(int i=k-2;i>=k-SZ(to[no]);i--){
            ans*=i;
            ans%=MOD;
        }
    }
	for(auto s:to[no]){
		if(s==p)continue;
		
		dfs(s,no);
	}
}
int main(){
    int n;
    cin>>n>>k;
    REP(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs();
    ans*=k;
    ans%=MOD;
    OUT(ans);
	return 0;
}