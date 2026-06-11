//Robs Code

/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <iomanip>

/***********MACROS***************/
#define int long long int
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define pii pair<int,int>

using namespace std;

const int N = 1e5 + 1;
int n,m,i,j,k,l,x,y,z,cnt[3],sum[3];

/***********MAIN**************/
const int M = 998244353;
int power(int x, int y){
    x %= M;
    int ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % M;
        y >>= 1LL;
        x = (x * x) % M;
    }
    return ans;
}
int add(int a, int b){
    return((a % M + b % M) % M);
}
int sub(int a, int b){
    return((a % M - b % M + M) % M);
}
int mul(int a, int b){
    return(((a % M) * (b % M)) % M);
}
int divi(int a, int b){
    return(mul(a, power(b, M - 2)) % M);
}
int a[3001];
int dp[3001][3001];
int brute(int i,int s){
	if(s < 0){
		return 0;
	}
	if(s == 0){
		return power(2,n - i + 1);
	}
	if(i == n){
		return 0;
	}
	if(dp[i][s] != -1){
		return dp[i][s];
	}
	dp[i][s] = (2 * brute(i + 1,s) + brute(i + 1,s - a[i])) % M;
	return dp[i][s];
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	memset(dp,-1,sizeof dp);
	cout << divi(brute(0,m) , 2);
}
//.........