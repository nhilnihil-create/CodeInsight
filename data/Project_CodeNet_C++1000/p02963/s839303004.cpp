#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>


void solve(){
	ll s;
	cin >> s;
	
	const int v=1000000000;
	
	int x=(v-s%v)%v;
	int y=(s+x)/v;
	
	cout<<"0 0 1000000000 1 " << x << " " << y <<endl;
}

int main(){

    solve();
}
