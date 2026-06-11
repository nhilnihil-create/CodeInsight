#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n,k,mx;
	while(cin>>n>>k,n){
		int a[100000]={0},b[100000]={0};
		rep(i,n)cin>>a[i]; rep(i,k)b[0]+=a[i]; mx=b[0];
		rep(i,n-k)b[i+1]=b[i]+a[i+k]-a[i],mx=mx>b[i+1]?mx:b[i+1];
		cout<<mx<<endl;
	}
	return 0;
}