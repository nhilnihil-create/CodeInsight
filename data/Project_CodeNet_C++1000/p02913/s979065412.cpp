#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=3.14159265359;

int N;
string S;
int DP[5005][5005];

void solve(int start){
    int from1=-1, to1=-1;
    int from, to;
    for(int i=1;i<N;++i){
        from = start + i;
        if((from1==-1) || (to1<from)){
            to = 0;
            while(from+to<N && S[start+to]==S[from+to]){
                to++;
            }
            DP[start][from] = to;
            from1 = from;
            to1 = from+to;
        }
        else{
            int k = from - from1;
            if(from + DP[start][start+k]<to1){
                DP[start][from] = DP[start][start+k];
            }
            else if(from + DP[start][start+k]>to1){
                DP[start][from] = to1 - from;
            }
            else{
                to = 0;
                while(to1+to<N && S[to1+to]==S[start+to1-from1-k+to]){
                    to++;
                }
                DP[start][from] = to + to1 - from;
                to1 = to1 + to;
                from1 = from;
            }
        }
    }
    DP[start][start] = N - start;
}

int main() {
    cin>>N>>S;
    for(int i=0;i<N;++i){
        solve(i);
    }
    int ans = 0;
    /**
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    **/
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            ans = max(ans, min(j-i, DP[i][j]));
        }
    }
    cout<<ans<<endl;
}
