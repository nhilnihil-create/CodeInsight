#include <bits/stdc++.h>

using namespace std;

#define maxn 1000005
#define int long long
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//	IN;
	int n, k;
	cin >> n >> k;
    if(k==1 || n==k ){
        cout << 0 << endl;
        return 0;
    }
    int ans = n-k;
    cout << ans << endl;

	return 0;
}
