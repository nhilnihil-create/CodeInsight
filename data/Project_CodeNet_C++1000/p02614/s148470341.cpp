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
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<char> > c(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) cin>>c[i][j];
    }
    int ans=0;
    for(int gyou=0;gyou<(1<<h);gyou++){
        for(int retu=0;retu<(1<<w);retu++){
            int num=0;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(gyou>>i&1 && retu>>j&1 && c[i][j]=='#') num++;
                }
            }
            if(num==k) ans++;
        }
    }
    cout<<ans<<endl;

}