#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ps(x,y) fixed<<setprecision(y)<<x
#define w(t) int t;cin>>t;while(t--)solve()
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define f(n) for (int i=0;i<n;++i)
#define init(arr,m,n,value) std::fill(*arr,*arr+m*n,value)
#define low(s) transform(s.begin(),s.end(),s.begin(),::tolower)
#define up(s) transform(s.begin(),s.end(),s.begin(),::toupper)
//debug("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

int gcd(int a , int b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//clock_t z = clock();
	int n;
	cin>>n;
	f(n)cout<<"ACL";

}
