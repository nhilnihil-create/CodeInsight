#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int n;
	while(cin >> n , n){
		int ans[2] = {0};
		rep(i,n){
			int a,b;
			cin >> a >> b;
			if(a==b)ans[0] += a , ans[1] += b;
			else ans[a<b] += a+b;
		}
		cout << ans[0] << " " << ans[1] << endl;
	}
}