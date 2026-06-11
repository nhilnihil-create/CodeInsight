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
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N, X, tmp, cnt;  cin >> N >> X;
    tmp = 0;
    cnt = 1;
    for(int i=0; i<N; i++){
        int l;  cin >> l;
        tmp += l;
        if(tmp <= X)    cnt++;
    }
    print(cnt);
}