#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#include<string>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int K;  cin >> K;
    string S;   cin >> S;
    int l = S.length();
    if(l <= K)  print(S);
    else    print(S.substr(0,K)+"...");
}