#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#include<set>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    sort(all(v));
    vector<int> c(1000001,0), d(1000001,0);
    for(int i=0; i<N; i++){
        int a = v[i];
        if(c[a] == 0 && d[a] == 0){
            for(int j=a+a; j<1000001; j+=a)   c[j] = 1;
            d[a] = 1;
        }
    }
    for(int i=1; i<N; i++) if(v[i] == v[i-1])  c[v[i]] = 1;

    int cnt = 0;
    for(int i=0; i<N; i++) if(c[v[i]] == 0) cnt++;
    print(cnt);
}