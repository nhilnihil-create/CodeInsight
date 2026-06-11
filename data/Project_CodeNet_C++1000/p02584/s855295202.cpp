

/******************************************************/
/******************************************************/
/**                                                  **/
/**            BISMILLAHIR RAHMANIR RAHIM            **/
/**         REAZ AHAMMED CHOWDHURY - reaziii         **/
/**  Department of Computer Science and Engineering  **/
/*         INSTITUTE OF SCIENCE AND TECHNOLOGY       **/
/**                                                  **/
/******************************************************/
/******************************************************/



#include<bits/stdc++.h>
#define sc(x)        scanf("%lld",&x)
#define pcase(x)     printf("Case %d: ",x++)
#define pn           printf("\n")
#define fri(f)       for(int i=0;i<f;i++)
#define frj(f)       for(int j=0;j<f;j++)
#define reset(x,e)   memset(x,e,sizeof(x))
#define all(x)       x.begin(),x.end()
#define input        freopen("input.txt","r",stdin);
#define output       freopen("output.txt","w",stdout)
#define infi         INT_MAX
#define m_v          3000000
#define pii          pair<int,int>
#define pch          pair<char,char>
#define pll          pair<ll,ll>
#define mgraph       map<int,vector<int> >
#define mp           make_pair
#define pb           push_back
#define clr(x)       memset(x,0,sizeof(x))
#define frx(x,y)     for(int x=0;x<y;x++)
#define ff           first
#define ss           second
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
bool checkbitt(ll num, int pos);
ll setbitt(ll num, ll pos);
ll resetbitt(ll num, int pos);
const ll mod =       1e9 + 7;
const ll N =     1e6 + 10;


//.................___Start from here___.................//
//.................._____________________................//




int solve() {
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	ll a = min(x / d, k);
	x -= d * a;
	k -= a;
	k &= 1;
	if (k) {
		ll p = x + d;
		ll q = x - d;
		x = min(abs(p), abs(q));
	}

	cout << x << endl;




	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	input;
	output;
#endif
#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#endif
	int cs = 1;
	int cn = 1;
	//cin>>cs;
	while (cs--) {
		solve();

	}
}


bool checkbitt(ll num, int pos) {return (num >> pos) & 1;}
ll setbitt(ll num, ll pos) {return (1 << pos) | num;}
ll resetbitt(ll num, int pos) {if (!checkbitt(num, pos)) return num; else return (1 << pos)^num;}

