#include <iostream>
using namespace std;
typedef long long ll;
const int N=60;

int n;
int d[N];

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++) cin>>d[i];
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			sum+=d[i]*d[j];
	
	cout<<sum;
	return 0;
}