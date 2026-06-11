#include <iostream>
using namespace std;
int summ(int x, int d[], int n)
{
	int sum = 0;
	for(int i = (x+1); i<n ; i++)
	{
		sum = sum + d[i];
	}
	sum = (sum*d[x]);
	return sum;
}

int main(){
	int N, i, res;
	res = 0;
	cin>>N;
	int d[N];
	for(i=0; i<N; i++)
	{
		cin>>d[i];
	}
	for(i = 0; i<N; i++)
	{	
		res = res + summ(i, d, N);
	}
	cout<<res;
	return 0;
}