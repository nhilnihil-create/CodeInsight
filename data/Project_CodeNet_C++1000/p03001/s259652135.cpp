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
    ld h,w,x,y;
    cin>>w>>h>>x>>y;
    cout<<setprecision(10)<<h*w/2.0<<" ";

    if(y==h/2.0 && x==w/2.0){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    
}