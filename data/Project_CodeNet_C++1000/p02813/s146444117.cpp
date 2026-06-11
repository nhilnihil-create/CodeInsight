#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr1[10];
int arr2[10];
int visited[10]={0};
int x1,x2;
int cnt=0;
void find(int size,vector<int>mn)
{
	if(size==0){
		cnt++;
		int flag=0;
		for(int i=0; i<n; i++){
			if(arr1[i]!=mn[i]){
				flag=1;
				break;
			}
		}
		if(flag==0)
		 x1=cnt;
		flag=0;
		for(int i=0; i<n; i++){
			if(arr2[i]!=mn[i]){
				flag=1;
				break;
			}
		}
		if(flag==0)
		 x2=cnt;
		return ;
	}
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			visited[i]=1;
			mn.push_back(i);
			find(size-1,mn);
			visited[i]=0;
			mn.pop_back();
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0; i<n; i++)
	 cin>>arr1[i];
	for(int i=0; i<n; i++)
	 cin>>arr2[i];
	vector<int>mn;
	find(n,mn);
	cout<<abs(x1-x2);
     return 0;
}