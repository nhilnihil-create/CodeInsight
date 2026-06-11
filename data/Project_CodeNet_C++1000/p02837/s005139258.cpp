#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll dp[1000100][2];


int main(){
    int n;
    cin>>n;
    vector<vector<P> > v(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        while(a){
            a--;
            int x,y;
            cin>>x>>y;
            x--;
            v[i].push_back(P(x,y));
        }
    }
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> justice;
        vector<int> unjus;
        for(int i=0;i<n;i++){
            if(1 & bit>>i){
                justice.push_back(i);
            }else{
                unjus.push_back(i);
            }
        }

        vector<bool> f(n,false);
        bool flag=true;

        for(int i:justice){
            f[i]=true;
        }
        for(int i:unjus){
            f[i]=false;
        }
        for(int i:justice){
            for(int j=0;j<v[i].size();j++){
                int x=v[i][j].first;
                int y=v[i][j].second;
                y=(bool)y;
                if(f[x]!=y){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) ans=max(ans,(int)justice.size());
    }
    cout<<ans<<endl;

}