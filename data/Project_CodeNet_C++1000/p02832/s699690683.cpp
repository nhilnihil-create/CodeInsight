#include<bits/stdc++.h>
using namespace std;
int main()

{
int n;
cin>>n;
vector<int>  a(n);
for(int i=0;i<n;i++) cin>>a[i];
if(*min_element(a.begin(),a.end()) != 1) {
	cout<<"-1";
	return 0;
}
vector<int> p;
int k=1;
for(int i=0;i<n;i++)
{  int j=i;
	for( j=i;j<n;j++)
	{
		if(a[j]==k)
		{  k++;
			p.push_back(j);
			
			break;
		}
	}
	i=j;
	
}
//for(auto x : p) cout<<x<<' ';
cout<<n-p.size()<<endl;
}