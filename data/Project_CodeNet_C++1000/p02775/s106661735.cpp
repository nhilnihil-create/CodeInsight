#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 8010
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 998244353;
int main(){
    string s;
    cin>>s;
    s='0'+s;
    int ans=0;
    reverse(ALL(s));
    REP(i,SZ(s)){
        int p=s[i]-'0';
        if(p>=6){
            int k=i+1;
            while(s[k]=='9')s[k++]='0';
            s[k]++;
        }else if(s[i]=='5'){
            if(s[i+1]>='5'){
                int k=i+1;
                while(s[k]=='9')s[k++]='0';
                s[k]++;
            }
        }
        ans+=min(p,10-p);
    }
    OUT(ans);
    return 0;
}