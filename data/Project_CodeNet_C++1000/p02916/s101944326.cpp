/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,res=0;
    cin>>n;
    vector<int> a(n);
    for(auto &i: a)
    {
    	cin>>i;--i;
    }
    vector<int> b(n);
    for(auto &i: b)
    	cin>>i;
    vector<int> c(n-1);
    for(auto &i: c)
    	cin>>i;
    for(int i=0;i<n;++i)
    {
    	res+=b[a[i]];
    	if(i>0&&a[i]-a[i-1]==1)
    		res+=c[a[i-1]];
    }
    cout<<res<<endl;
}