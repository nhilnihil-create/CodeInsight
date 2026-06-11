#include <bits/stdc++.h>
#include <list>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;


int main(){
    int N,M;
    cin >> N >> M;
    int ans = 0;
    int a,b;
    a=0;
    b=0;
    if(N!=0&&N!=1) a = N * (N-1);
    a /= 2;
    
    if(M!=0&&M!=1) b = M * (M-1);
    b /= 2;
    ans = a+b;
    cout << ans << endl;
}