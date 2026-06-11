#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 100005
#define MOD 20190823
#define eps 1e-8
#define bl bool
#define INF 1e+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
template<class T> inline void read(T &f){
	f=0;
    T x=1;
    char ch=getchar();
    while(ch<48 || ch>57) {
        if(ch=='-') {
            x=-1;
        }
        ch=getchar();
    }
    while(ch<=57 && ch>=48) {
        f=f*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
int main(){
	ll n,k;
	read(n),read(k);
	ll ans=0;
	for(ll i=22;i<=k;i++)
	{
		ll first=i%10;
		ll second=i/10;
		if(first<2 || second<2){
			continue;
		}
		if(first*second<=n){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}