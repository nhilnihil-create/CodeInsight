#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e17;
 
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
 
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}



signed main()
{
	IOS();
	int N,P;
	vector<int>ans;
	while(1){
		cin>>N>>P;
		if(N==0&&P==0)break;
		int turn = 0;
		int sum = P;
		int a[N] = {};
		while(1){
			if(sum){
				a[turn]++;
				sum--;
			}else{
				sum+=a[turn];
				a[turn]=0;
			}
			if(a[turn]==P){
				ans.push_back(turn);
				break;
			}
			turn = (turn+1)%N;
		}
	}
	for(auto e:ans){
		cout<<e<<endl;
	}
}

