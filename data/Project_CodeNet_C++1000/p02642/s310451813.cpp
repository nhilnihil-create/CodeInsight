#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 4223352036854775007
#define iii pair<ll,ll>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define r0 return 0
#define pb push_back
#define sz size
using namespace std;

const char E='\n';
const int N=2000005;
const int NN=2005;
const ll md=998244353;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b,n,t,tmp;
	cin>>n;
	vii v,v1(N,0);
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
		tmp=v[i];
		for(int j=tmp;j<=v[n-1];j+=tmp)
            v1[j]++;
	}
	ll cnt=0;
	for(int i=0;i<n;i++)
    {
        if(v1[v[i]]==1)
            cnt++;
    }
    cout<<cnt<<E;
    r0;
}


/*







*/
