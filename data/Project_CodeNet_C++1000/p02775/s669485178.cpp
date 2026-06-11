#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
const int MAXN=1000005;
const int MOD=1000000007;

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define DEC(i,a,b) for(int i=(a);i>=(b);i--)
#define fst first
#define snd second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define db(x) cerr<<#x<<" = "<<x<<"\n"
#define LOW(v,x) (lower_bound(all(v),(x))-(v).begin())
#define UP(v,x) (upper_bound(all(v),(x))-(v).begin())

int A[MAXN], N;
string S;

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>S;
	N=S.size();
	FOR(i,1,N)A[i]=(int)S[i-1]-'0';
	int ans=0;
	DEC(i,N,1){
		A[i-1]+=A[i]/10;
		A[i]=A[i]%10;
		if ((A[i]==5 && A[i-1]>=5) || A[i]>5){
			ans+=10-A[i];
			A[i-1]++;
		}
		else ans+=A[i];
	}
	ans+=A[0];
	cout<<ans;
}
