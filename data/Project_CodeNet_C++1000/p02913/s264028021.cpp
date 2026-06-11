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

string s;

const int N=5e3+100;
const ll mod=1e9+7;
const ll bas=101;

ll __hash[N][N];

void brute_hash(){
	int n=sz(s);
	roF(i,n-1,0)For(j,i,n){
		__hash[i][j]=((s[i]-'a'+1)+__hash[i+1][j]*bas)%mod;
	}
}



int main(){	
	int n;cin>>n;
	cin>>s;
	brute_hash();
	int mx=0;
	For(i,0,sz(s)){
		int lo=0,hi=n-i;
		while(lo+1<hi){
			int mid=(lo+hi)>>1;
			bool _find=false;
			For(j,i+mid,n){
				if(__hash[i][i+mid-1]==__hash[j][j+mid-1]){
					_find=true;
					break;
				}
			}
			if(_find)lo=mid;
			else hi=mid;
		}
		mx=max(mx,lo);
	}
	cout<<mx<<endl;

	return 0;
}
