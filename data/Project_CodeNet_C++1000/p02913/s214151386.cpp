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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;
int Z[6001][6001];
void z_alg(int l, int n, string s){
    Z[l][l]=n-l;
    int j=0;
    for(int i=l+1;i<n;i++){
        while(i+j<n && s[l+j]==s[i+j]) j++;
        Z[l][i]=j;
        if(j==0) continue;
        int k=1;
        while(k<j && Z[l][l+k]+k<j){
            Z[l][i+k]=Z[l][l+k];
            k++;
        }
        i+=k-1;
        j-=k;
    }
}

int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        z_alg(i,n,s);
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int buf=min(j-i,Z[i][j]);
            ans=max(ans,buf);
        }
    }
    cout<<ans<<endl;
}