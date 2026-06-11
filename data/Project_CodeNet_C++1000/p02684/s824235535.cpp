#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#include<string>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main()
{
    ll N, K;    cin >> N >> K;
    vector<int> v(N+1), c(N+1,0);
    for(int i=1; i<N+1; i++)  cin >> v[i];
    int now = 1, l, r;
    for(int i=1; i<=min(N+5,K); i++){
        now = v[now];
        if(c[now] > 0){
            l = i - c[now];
            r = (K - c[now])%l;
            for(int j=0; j<r; j++)  now = v[now];
            cout << now;
            return 0;
        }
        c[now] = i;
    }
    cout << now;
}