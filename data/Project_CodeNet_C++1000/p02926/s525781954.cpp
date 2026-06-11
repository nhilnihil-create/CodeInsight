#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1000000000
#define rep(i,a,b) for(int i =(a);i<(b);i++)
#define fs first
#define ss second
inline int Scan() {
    int x=0;int f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

template<typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}

// call by reference is used in x
template<typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
//////////////////////////////////////end of template//////////////////////////////////////

int main(){

   int n;
   cin >> n;
   
   vector<pair<double, pair<double,double> > > deg;
   
   rep(i,0,n){
	  
	  double x,y;
	  cin >> x >> y;
	  deg.push_back(mp(atan2(y,x),mp(x,y))); 
	   
   }
	 sort(deg.begin(),deg.end());
	 
	long double ans = 0;
	
	rep(i,0,n){
		long double x = 0.0000;
		long double y = 0.0000;
		
		rep(j,0,n){
		 
		 x+= deg[(i+j)%n].ss.fs;
		 y+= deg[(i+j)%n].ss.ss;
		 amax(ans,sqrt(x*x + y*y));
		 
	}
	
	}
	 
	 cout << setprecision(30) << ans <<endl;
	     
	   
   } 



