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

const int N=2e5+100;
ll arr[N],L[N],R[N];

int main(){	
	ll n,k,q;cin>>n>>k>>q;	
	For(i,0,q){
		int val;cin>>val;
		val--;
		arr[val]++;
	}
	L[0]=arr[0];
	For(i,0,n)L[i]=L[i-1]+arr[i];
	R[n-1]=arr[n-1];
	roF(i,n-2,0)R[i]=R[i+1]+arr[i];
	For(i,0,n){
		ll val=0;
		if(i+1<n)val+=R[i+1];
		if(i-1>=0)val+=L[i-1];
		if(k-val<=0)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}


	return 0;
}
