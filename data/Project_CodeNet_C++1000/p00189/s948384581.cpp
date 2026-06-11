#include<bits/stdc++.h>
#define sd(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define slld(x) scanf("%lld",&x)
#define me(x,b) memset(x,b,sizeof(x))
#define pd(d) printf("%d\n",d);
#define plld(d) printf("%lld\n",d);
#define eps 1.0E-8
// #define Reast1nPeace

typedef long long ll;

using namespace std;

const int INF = 0x3f3f3f3f;

int mapp[15][15];

int main(){
#ifdef Reast1nPeace
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n && n){
		memset(mapp,INF,sizeof(mapp));
		
		int m = -1;
		for(int i = 0 ; i<n ; i++){
			int a,b,c; cin>>a>>b>>c;
			mapp[a][b] = mapp[b][a] = c;
			m = max(m , max(a,b));
		}
		
		for(int k = 0 ; k<=m ; k++){
			for(int i = 0 ; i<=m ; i++){
				for(int j = 0 ; j<=m ; j++){
					if(i==j) continue;
					if(mapp[i][j] > mapp[i][k]+mapp[k][j]){
						mapp[i][j] = mapp[i][k]+mapp[k][j];
					}
				}
			}
		}
		
		int id; int minn = INF;
		for(int i = 0 ; i<=m ; i++){
			int sum = 0;
			for(int j = 0 ; j<=m ; j++){
				if(i==j) continue;
				sum += mapp[i][j];
			}
			if(minn > sum){
				minn = sum;
				id = i;
			}
		} 
		cout<<id<<" "<<minn<<endl;
	}
	return 0;
}

