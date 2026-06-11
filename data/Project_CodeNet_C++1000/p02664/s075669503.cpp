#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fw(p) for(int w=0;w<(p);w++)
#define fx(p) for(int x=0;x<(p);x++)
#define fy(p) for(int y=0;y<(p);y++)
#define fz(p) for(int z=0;z<(p);z++)
#define fyg(p,g) for(int y=(g);y<(p);y++)
#define fzg(p,g) for(int z=(g);z<(p);z++)
#define ce(d) cout<<d<<endl;
#define vecp(p) int aa;cin>>aa;(p).push_back(aa);
#define vecpl(p) long long aa;cin>>aa;(p).push_back(aa);
#define vecps(p) string aa;cin>>aa;(p).push_back(aa);
#define vecp2(p) cin>>aa;(p).push_back(aa);
#define vecpl2(p) long long a	b;cin>>ab;(p).push_back(ab);
#define vecps2(p) string ab;cin>>ab;(p).push_back(ab);
#define sorts(c) sort((c).begin(),(c).end());
#define reverses(c) reverse((c).begin(),(c).end());
#define vec(b) vector<int> (b);
#define vecl(b) vector<long long> (b);
#define vecs(b) vector<string> (b);
#define pb(b,a) (b).push_back((a));
#define doublece(a,b) cout<<(a)<<' '<<(b)<<endl;
#define pairs(s) vector<pair<int,int>> (s);
#define pairsp(s) int aa,bb;cin>>aa>>bb;(s).push_back(make_pair(aa,bb));
#define MOD 1000000007
#define cey ce("Yes")
#define cen ce("No")
#define ceY ce("YES")
#define ceN ce("NO")

int main()
{
string T;
	cin >> T;

	fx(T.size()) {
		if (T[x]!='?') {
			continue;
		}
		if (x == 0) {
			if (T[1]=='D'||T[1]=='?') {
				T[0] = 'P';
			}
			else {
				T[0] = 'D';
			}
		}
		else if (x==T.size()-1) {
			T[x] = 'D';
		}
		else {
			if (T[x-1]=='P') {
				T[x] = 'D';
			}
			else if (T[x+1]=='D' || T[1] == '?') {
				T[x] = 'P';
			}
			else {
				T[x] = 'D';
			}
		}
	}
	ce(T)
    return 0;
}

