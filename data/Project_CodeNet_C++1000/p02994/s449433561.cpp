#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;

int main(){
    int n,l;
	cin>>n>>l;
	int ans = INF;
	int num = INF;
	int m = 0;
	rep(i,1,n+1){
		if (num>abs(i+l-1)){
			ans = i+l-1;
			num = abs(i+l-1);
		}
		m+=i+l-1;
	}
	cout<<m-ans<<endl;
}