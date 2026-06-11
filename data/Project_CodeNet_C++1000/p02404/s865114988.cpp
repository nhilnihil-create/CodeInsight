#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int H, W;

int main(){
	cin.tie(0);
	
	while(cin>>H>>W,H||W) {
	    rep(i, H) {
	        rep(j, W) {
	            if(i==0||j==0)cout<<'#';
	            else if(i==H-1||j==W-1)cout<<'#';
	            else cout<<'.';
	        }
	        cout<<endl;
	    }
	    cout<<endl;
	}

	return 0;
}

