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
    int n=0,x=0;
    cin>>n;
    multiset<int, greater<int> > ms;
    for(int i=0;i<(1<<n);++i)
    {
    	cin>>x;ms.insert(x);
    }
    /*for(auto i: ms)
    {
    	cout<<i<<" ";
    }
    cout<<endl;*/
    vector<int> v;
    v.pb(*ms.begin());
    ms.erase(ms.begin());
    for(int i=0;i<n;++i)
    {
    	vector<int> aux;
    	for(int j=0;j<(int)v.size();++j)
    	{
    		if(ms.upper_bound(v[j])==ms.end())
    		{
    			cout<<"No"<<endl;
    			return 0;
    		}
    		aux.pb(*(ms.upper_bound(v[j])));
    		ms.erase(ms.upper_bound(v[j]));
    	}
    	for(int j=0;j<(int)aux.size();++j)
    		v.pb(aux[j]);
    	sort(v.begin(),v.end());
    }
    cout<<"Yes"<<endl;
}