#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
int main(){
	int a,b,n,x,y;
	while(cin>>a>>b,a){
		int p[17][17]={0},k[17][17]={0};
		cin>>n; while(n--)cin>>x>>y,k[y][x]=1;
		rep1(i,b)rep1(j,a)p[i][j]=i==1&&j==1?1:(p[i-1][j]+p[i][j-1])*(1-k[i][j]);
		cout<<p[b][a]<<endl;
	}
	return 0;
}