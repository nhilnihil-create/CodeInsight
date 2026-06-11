#include <iostream>
#include <algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

vector <int> ve[100010];
int a[100020];
int dfs (int b)
{
	a[b]=1;
	for(int i=0;i<ve[b].size();i++)
	{
		if(a[ve[b][i]]==0)
		{
			dfs(ve[b][i]);
		}
	}
	return 0;
}


int main() {
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	a[i]=0;
}
int ve1,ve2;
for(int i=0;i<m;i++)
{
	cin>>ve1>>ve2;
	ve[ve1].push_back(ve2);
	ve[ve2].push_back(ve1);
}
int ans=0;
for(int i=1;i<=n;i++)
{

	if(a[i]==0)
	{
		dfs(i);
	
      	ans+=1;
    }
}
cout<<ans-1<<endl;
    
	return 0;
}