#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    int N, tmp, ans;  cin >> N;
    vector<int> v(N);
    ans = 10000000;
    for(int i=0; i<N; i++)  cin >> v[i];
    for(int i=0; i<103; i++){
        tmp = 0;
        for(int j=0; j<N; j++)  tmp += (v[j] - i)*(v[j] - i);
        ans = min(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}