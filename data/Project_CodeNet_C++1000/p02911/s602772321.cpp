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
    int n=0,k=0,q=0,x=0;
    cin>>n>>k>>q;
    vector<int> v(n);
    vector<int> a(n,0);
    for(int i=0;i<n;++i)
    	{
    		v[i]=k;a[i]=0;
    	}
    for(int i=0;i<q;++i)
    {
    	cin>>x;
    	++a[x-1];
    }
    for(int i=0;i<n;++i)
    {
    	v[i]-=(q-a[i]);
    	//cout<<v[i]<<" ";
    }
    for(auto i: v)
    {
    	cout<<(i<=0?"No":"Yes")<<endl;
    }
}