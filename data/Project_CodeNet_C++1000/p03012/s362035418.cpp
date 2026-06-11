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
    vector<int> w;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        w.push_back(m);
    }

    int sum=0;
    for(int i=0;i<n;i++) sum+=w.at(i);

    int ans=sum;
    int tmp=0;
    for(int i=0;i<n;i++){
        tmp+=w.at(i);
        ans=min(ans,abs((sum-tmp)-tmp));
        //cout << ans << endl;
    }

    cout << ans << endl;
}