// I look at my watch
// it say nine twenty-five
// And I think oh God
// I'm still alive
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

const int N=200;
int w[N];


int main(){	
	int n;cin>>n;
	For(i,0,n)cin>>w[i];
	int mx=INT_MAX;
	For(i,0,n-1){
		int sum1=0,sum2=0;
		For(j,0,i+1)sum1+=w[j];
		For(j,i+1,n)sum2+=w[j];
		mx=min(mx,abs(sum1-sum2));
	}
	cout<<mx<<endl;

	return 0;
}
