#include <bits/stdc++.h>  

const int INF =1e9;
const int MOD =1e9+7;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] ={ 1, 0, -1, 0 };
int dy[4] ={ 0, 1, 0, -1 };


int main()
{
    int k;
    cin>>k;
    vector<ll> ans;
    queue<ll> Q;
    FOR(i,1,10)
        Q.push(i);
    while(ans.size()<100000){
        queue<ll> Q2;
        while(!Q.empty()){
            ll q=Q.front();
            Q.pop();
            ans.push_back(q);
            for(int i=-1;i<=1;i++){
                if(0<=(q%10+i)&&(q%10+i)<10){
                    Q2.push(q*10+(q%10+i));
                }
            }
        }
        Q=Q2;
    }
    cout<<ans[k-1]<<endl;
}