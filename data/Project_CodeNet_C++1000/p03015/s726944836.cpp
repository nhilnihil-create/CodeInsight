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
ll I[N];
ll m[N];
int main(){
    string s;
    IN(s);
    I[0]=1;
    REP(i,SZ(s)){
        if(s[i]=='1'){
            I[i+1]=2*I[i];
            m[i+1]+=I[i];
        }else{
            I[i+1]=I[i];
        }
        m[i+1]+=3*m[i];
        m[i+1]%=MOD;
        I[i+1]%=MOD;
    }
    OUT((I[SZ(s)]+m[SZ(s)])%MOD);
	return 0;
}