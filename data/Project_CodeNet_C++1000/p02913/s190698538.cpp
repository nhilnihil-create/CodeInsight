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
vector<int> Z(string &s)
{
	int n=(int)s.length();
	vector<int> z(n);
	for(int i=1,l=0,r=0;i<n;++i)
	{
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
			++z[i];
		if(i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	return z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,res=0;string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;++i)
    {
    	string str=s.substr(i);
    	vector<int> aux=Z(str);
    	for(int j=0;j<(int)aux.size();++j)
    	{
    		int len=min(aux[j],j);
    		res=max(res,len);
    	}
    }
    cout<<res<<endl;
}