#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin>>N;
	vector<int>arr(N);
	for(int i=0; i<N; i++)
	 cin>>arr[i];
	int flag=0;
	for(int i=0; i<N; i++){
		if(arr[i]%2==0)
		{
			if(arr[i]%3!=0 && arr[i]%5!=0)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag)
	 cout<<"DENIED";
	else
	 cout<<"APPROVED";
	return 0;
	
}