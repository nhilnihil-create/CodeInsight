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
    map<string,int> mp;
    int N;  cin >> N;
    for(int i=0; i<N; i++){string S; cin >> S; mp[S]++;}
    int m = 0;
    for(auto it=mp.begin(); it!=mp.end(); it++) m = max(m,it->second);
    for(auto it=mp.begin(); it!=mp.end(); it++) if(it->second == m) print(it->first);
}