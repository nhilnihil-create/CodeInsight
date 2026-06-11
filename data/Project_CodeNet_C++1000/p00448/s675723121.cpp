#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int r,c;
int sen[10][10000];
int count(int b){
	int ans=0;
	int tsen[10][10000];
	rep(i,r)rep(j,c)tsen[i][j]=sen[i][j]^(!!(b&(1<<i)));
	rep(j,c){
		int t=0;
		rep(i,r)t+=tsen[i][j];
		ans+=t>r-t?t:r-t;
	}
	return ans;
}
int main(){
	while(cin>>r>>c,r){
		rep(i,r)rep(j,c)cin>>sen[i][j];
		int mx=0,tmp;
		rep(i,1<<r){
			tmp=count(i);
			if(mx<tmp)mx=tmp;
		}
		cout<<mx<<endl;
	}
}