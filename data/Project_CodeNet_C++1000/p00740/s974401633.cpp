#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#define rep(i,l,n) for(lint i=l;i<n;i++)
#define rer(i,l,n) for(lint i=l;i<=n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef vector<int> vi;
typedef vector<lint> vli;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main(){
	int n, p;
	while (1){
		cin >> n >> p;
		vi d(55);
		if (n == 0 && p == 0) break;
		int ans = 0, now = 0, np = p;
		for (int i = 0;; i++){
			if (np){
				d[now]++;
				np--;
				if (np == 0 && d[now] == p){
					ans = now; break;
				}
			}
			else{
				np = d[now];
				d[now] = 0;
			}
			now++;
			if (now == n) now = 0;
		}
		o(ans);
	}
}