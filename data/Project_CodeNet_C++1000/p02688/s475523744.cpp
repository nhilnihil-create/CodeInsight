#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <sstream>

#define endl "\n"
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
using Graph = vector<vector<int>>;

int main(){
    int n,k;
    cin>>n>>k;
    int d[k];
    vector<bool> treat(n,true);
    for(int i=0;i<k;i++){
        cin>>d[i];
        for(int j=0;j<d[i];j++){
            int a;
            cin>>a;
            treat[a-1] = false;
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        if(treat[i]) ans++;
    }
    cout<<ans<<endl;
}