#define rep(i, n) for(i = 0; i < n; i++)
#define repi(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
	int e;
	while(cin>>e, e){
		int x, y, z;
		int ans = 1000000;
		for(z = 100; z >= 0; z--){
			if(z*z*z > e)continue;
			for(y = 1000; y >= 0; y--){
				if(z*z*z + y*y > e)continue;
				if(ans > (e - z*z*z - y*y )+y+z)ans = (e - z*z*z - y*y )+y+z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}