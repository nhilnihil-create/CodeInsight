#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll mod=(int)1e9+7;

int main()
{
	ios;
	set<int> s;
	int n,k,p,i;
	cin>>k>>n;
	for(i=0;i<n;i++) 
	{
		cin>>p;
		s.insert(p);
	}
	p=0;
	while(true)
	{
		if(s.find(k-p)==s.end()) { cout<<k-p; break;}
		else if(s.find(k+p)==s.end()) { cout<<k+p; break;}
		p++;
	}

	
	return 0;
}
