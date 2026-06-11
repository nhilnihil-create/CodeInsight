#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int R,C;

int main()
{
	while(scanf("%d%d",&R,&C),R){
		vector< vector<int> > A(R,vector<int>(C));
		FOR(i,0,R) FOR(j,0,C){
			scanf("%d",&A [i] [j]);
		}

		int ans = 0;
		FOR(mask,0,1 << R){
			FOR(i,0,R) if(mask >> i & 1){
				FOR(j,0,C){
					A [i] [j] ^= 1;
				}
			}
			int res = 0;
			FOR(i,0,C){
				int cnt = 0;
				FOR(j,0,R){
					cnt += A [j] [i];
				}
				res += max(cnt,R - cnt);
			}
			chmax(ans,res);
			FOR(i,0,R) if(mask >> i & 1){
				FOR(j,0,C){
					A [i] [j] ^= 1;
				}
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}