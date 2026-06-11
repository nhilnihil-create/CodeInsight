#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;

ll n;
const int Mod=1e9+7;
ll ans=1,tot=1,cnt=1;

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	REP(i,n)ans=(ans*10)%Mod;
	REP(i,n)cnt=(cnt*9)%Mod;
	REP(i,n)tot=(tot*8)%Mod;
	cout<<(ans-2*cnt+tot+Mod+Mod)%Mod<<endl;
	return 0;
}
