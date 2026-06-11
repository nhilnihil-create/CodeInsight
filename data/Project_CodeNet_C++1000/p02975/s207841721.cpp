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

int main(){

	int N;
	cin >> N;
	vec(A);
	set<int> all;
	map<int, int> K;
	fx(N) {
		vecp(A);
		all.insert(A[x]);
		K[A[x]]++;
	}

	if (N==3) {
		if ((A[0]^A[2])==A[1]&&( A[1] ^ A[2]) == A[0]&& (A[1] ^ A[0])== A[2]) {
			cey;
		}
		else {
			cen;
		}
	}
	else {
		if (N%3==0) {
			if (all.size()>3) {
				cen;
			}
			else if (all.size()==3) {
				vec(B);
				for (int b : all) {
					pb(B, b);
				}
				int b[3] = {K[B[0]],K[B[1]] ,K[B[2]] };
				if (b[0]==b[1]&&b[1]==b[2]) {
					if ((B[0]^B[1])==B[2]&& (B[0] ^ B[2]) == B[1]&& (B[2] ^ B[1] )== B[0]) {
						cey;
					}
					else {
						cen;
					}
				}
				else {
					cen;
				}
			}
			else if (all.size()==2) {
				vec(B);
				for (int b : all) {
					pb(B, b);
				}
				int b[2] = { K[B[0]],K[B[1]]  };
				if (b[0] == b[1]*2 || b[1] == b[0]*2) {
					if (B[0] ==0||B[1]==0) {
						cey;
					}
					else {
						cen;
					}
				}
				else {
					cen;
				}
			}
			else {
				if (A[0]==0) {
					cey;
				}
				else {
					cen;
				}
			}


		}
		else {
			if (all.size() == 1 && A[0] == 0) {
				cey;
			}
			else {
				cen;
			}
		}
	}


    return 0;
}

