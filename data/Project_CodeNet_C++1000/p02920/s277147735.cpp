#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
#define rep(i,n) for (int i=0;i<n;++i)
#define REP(i,n) for (int i=1;i<=n;++i)
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define F first
#define S second
#define read(x) scanf("%d",&x)
int n,N;
multiset<int> a;
multiset<int> s;
multiset<int>::iterator it,IT;
int tmp[1000005],ptr;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;N=1<<n;
	for (int i=1;i<=N;++i){
		int x;cin>>x;a.insert(x);
	}
	it=a.end();--it;IT=it;--IT;
	if (*IT==*it){
		cout<<"No"<<endl;return 0;
	}
	s.insert(*it);a.erase(it);
	while(n--){
		it=s.end();--it;
		IT=a.end();--IT;
		ptr=0;bool flag=0;
		while(1){
			while(IT!=a.begin()&&*IT>=*it) --IT;
			if (IT==a.begin()&&*IT>=*it){
				cout<<"No"<<endl;return 0;
			}
			tmp[++ptr]=*IT;
			if (a.size()==1) a.erase(IT),flag=1;
			else IT=a.erase(IT);
			if (!flag) --IT;
			if (it==s.begin()) break;
			else --it;
			if (flag){
				cout<<"No"<<endl;return 0;
			}
		}
		for (int i=1;i<=ptr;++i) s.insert(tmp[i]);
	}
	cout<<"Yes"<<endl;
	return 0;
}