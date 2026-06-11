#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    char c[n];
    int cnt=0;
    for(int i=0;i<n;i++){
        cin >> c[i];
        if(c[i]=='R') cnt++;
    }

    int ans=0;
    for(int i=0;i<cnt;i++){
        if(c[i]=='W') ans++;
    }
    cout << ans << endl;
}