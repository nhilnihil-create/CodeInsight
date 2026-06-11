#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli n,a,b,c,q,sum=0;
    vector<lli> ans;
    map<lli,lli> map;
    lli i;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        sum+=a;
        map[a]++;
    }
    cin>>q;
    rep(i,0,q){
        cin>>b>>c;
        map[c]+=map[b];
        sum+=(c-b)*map[b];
        map[b]=0;
        ans.push_back(sum);
    }
    rep(i,0,q){
        cout<<ans[i]<<endl;
    }
}
