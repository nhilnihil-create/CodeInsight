#include <iostream>
#include <vector>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Forr(i,a,b) for(int i=a;i<b;++i)
#define Ford(i,a,b) for(int i=a;i>=b;--i)
#define Rep(i,a) for(int i=1;i<=a;++i)
#define Repp(i,a) for(int i=0;i<a;++i)
#define Repd(i,a) for(int i=a;i;--i)
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int N = 1e5+5;
const int mod = 1e9+7;
string t = "BW";
string s;
int n, l, cur = 1;
void End(){
	cout << 0;
	exit(0);
}
int Pow(int a, int b){
	int c = 1;
	for(; b; b>>=1, a=(1ll*a*a)%mod){
		if(b&1) c = (1ll*c*a)%mod;
	}
	return c;
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin. tie(NULL); cout. tie(NULL);
//	freopen(".inp" , "r", stdin);
//	freopen(".out", "w", stdout);
    cin >> n >> s;
    Repp(i,n+n){
		int temp = t.find(s[i]);
		if((l&1)==temp){
			++l;
		}else{
			cur = (1ll*cur*l)%mod;
			--l;
			if(l<0) End();
		}
    }
    if(l) End();
    Rep(i,n)cur = (1ll*cur*i)%mod;
    cout << cur;
    return 0;
}