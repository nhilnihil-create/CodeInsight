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
    int N, K, S;    cin >> N >> K >> S;
    ll MAX = 1000000000;
    if(S == MAX){
        for(int i=0; i<K; i++)  cout << MAX << " ";
        for(int i=K; i<N; i++)  cout << MAX-1 << " ";
    }else{
        for(int i=0; i<K; i++)  cout << S << " ";
        for(int i=K; i<N; i++)  cout << MAX << " ";
    }
}