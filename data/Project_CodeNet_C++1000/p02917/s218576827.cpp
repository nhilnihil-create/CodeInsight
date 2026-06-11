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
    int b[n-1];
    for(int i=0;i<n-1;i++) cin >> b[i];

    int ans=b[0];
    for(int i=0;i<n-2;i++) ans+=min(b[i],b[i+1]);
    ans+=b[n-2];

    cout << ans << endl;
}