#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <stack>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> bool cmin(T &a, const S &b) { if (a > b){a = b; return true;}return false; }
template<class T, class S> bool cmax(T &a, const S &b) { if (a < b){a = b; return true;}return false;}
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
typedef pair<ll,ll>pll;
int main(){
    int n;
    while(cin>>n,n){
        vector<ll>dp(300,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(i>=4)dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        ans=dp[n];
        cout<<ans/3650+(ans%3650?1:0)<<endl;
    }
}