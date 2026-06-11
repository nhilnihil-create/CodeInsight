#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);


int t(int h,int m,int s){
	return h*60*60+m*60+s;
}
int main(){
	int n;
	while(cin>>n,n){
		vector<pii> times(n);
		REP(i,n){
			int h1,m1,s1,h2,m2,s2;
			scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
			times[i]=make_pair(t(h1,m1,s1),t(h2,m2,s2));
		}
		sort(ALL(times));
		priority_queue<int,vi,greater<int> > q;
		REP(i,n){
			if(q.empty())
				q.push(times[i].second);
			else
			{
				if(q.top()<=times[i].first){
					q.pop();
					q.push(times[i].second);
				}else{
					q.push(times[i].second);
				}
			}
		}
		cout<<q.size()<<endl;
	}
}