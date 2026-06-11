#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()
#define mod 1000000007
#define inf 2147483647
int main(){
	int h,w,k;
	cin>>h>>w>>k;
	char c[h][w];
	rep(i,h)rep(j,w)cin>>c[i][j];
	int row[h],col[w],count,ans=0;
	rep(i,1<<h){
		rep(o,h)row[o]=(i>>o)&1;
		rep(j,1<<w){
			rep(o,w)col[o]=(j>>o)&1;
			count=0;
			rep(a,h)rep(b,w){
				if(row[a]==0&&col[b]==0){
					if(c[a][b]=='#'){
						count++;
					}
				}
			}
		if(count==k)ans++;
		}
	}
	cout<<ans;		
	return 0;
}