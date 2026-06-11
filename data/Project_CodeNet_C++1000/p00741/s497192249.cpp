#define rep(i, n) for(int i = 0; i < n; i++)
#define ck(a, b) (0<=a && a<b)
using namespace std;
int dx[]={-1,0,1,-1,1,-1,0,1}, dy[]={-1,-1,-1,0,0,1,1,1};
int w, h; int il[50][50];

int main(){
	while(cin>>w>>h, w||h){
		int c = 0;
		rep(y, h)rep(x, w)cin>>il[y][x];
		rep(y, h)rep(x, w){
			if(il[y][x]){
				int cked[50][50] = {0};
				cked[y][x] = 1;
				bool finish = 0;
				while(!finish){
					finish = 1;
					rep(i, h)rep(j, w){
						if(cked[i][j]){
							rep(d, 8){
								if(ck(j+dx[d],w) && ck(i+dy[d],h) &&
									il[i+dy[d]][j+dx[d]] &&
									!cked[i+dy[d]][j+dx[d]]
								){
									cked[i+dy[d]][j+dx[d]] = 1; finish = 0;
								}
							}
						}
					}
				}
				c++;
				rep(i, h)rep(j, w)if(cked[i][j])il[i][j]=0;
			}
		}
		cout<<c<<endl;
	}
	return 0;
}