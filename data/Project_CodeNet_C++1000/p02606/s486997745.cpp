//--------------------------------------------------------------------------------
// Code By:
//					######                  #               ######
//					##   #                  #               #
//					#####      ##       #####      ##       #   ###
//					##   #              #   #               #   # #
//					##    #	            #####               ##### #
//---------------------------------------------------------------------------------

#include<bits/stdc++.h>
using namespace std;

                             /* ----------------------------- START of Template ---------------*/
#define ll long long int
#define FOR(x,to) for(x=0;x<(to);x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<long long int> >
#define vll vector<long long int>
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SZ(X) ((int)(X).size())
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second

void getZarr(string str, vll &Z)
{
    ll n = str.length();
    ll L, R, k;
    L = R = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
   } } }}
vector<ll>isprime;
void seive(ll size){
	isprime.resize(size+1,1);
	ll i,j;
	isprime[0]=0;
	isprime[1]=0;
	for(i=2;i*i<=size;i++){
		if(isprime[i]){
			for(j=2;j*i<=size;j++)isprime[i*j]=0;
		}
	}
}
ll power(ll x,unsigned ll y, ll m){
	if(y==0)return 1;
	ll p=power(x,y/2,m);
	p=(p*p)%m;
	if(y%2!=0)p=(p*x)%m;
	return p;
}
ll modinverse(ll a,ll m){
	return power(a,m-2,m);
}


                       /* ----------------------          End Of Template --------------------------------*/

ll findans(){
	ll l,r,d;
	cin>>l>>d>>r;
	ll ans=d/r-l/r;
	if(l%r==0)ans++;
	cout<<ans<<endl;
	return 0;



}

int main(){
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll t,i;
//	cin>>t;
t=1;
	for(i=0;i<t;i++){
		findans();
	}
return 0;
}




