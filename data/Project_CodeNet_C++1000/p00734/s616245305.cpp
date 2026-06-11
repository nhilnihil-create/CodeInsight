#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n,m;
	while(cin>>n>>m,n){
		int cd[200]; int t=0,h=0;
		rep(i,n)cin>>cd[i],t+=cd[i];
		rep(i,m)cin>>cd[i+n],h+=cd[i+n];
		sort(cd,cd+n),sort(cd+n,cd+n+m);
		
		rep(i,n)rep(j,m){
			if(t-cd[i]+cd[j+n]==h-cd[j+n]+cd[i]){
				cout<<cd[i]<<" "<<cd[j+n]<<endl;; goto NEXT;
			}
		}
		cout<<-1<<endl;
		NEXT:;
	}
	return 0;
}