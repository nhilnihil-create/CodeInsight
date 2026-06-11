#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 367
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int n;
void dfs(string s="",char max='a'){
    if(SZ(s)==n)OUT(s);
    else{
        for(char c='a';c<=max;c++){
            dfs(s+c,((c==max)?char(max+1):max));
        }
    }
}
int main(){
    cin>>n;
    dfs();
    return 0;
}