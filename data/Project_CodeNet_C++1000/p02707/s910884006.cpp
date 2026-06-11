#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector <int> vect(N+1,0);
	int i,j,k;
	for(i=0;i<N-1;i++)
	{
		cin>>j;
		vect[j]++;
	}
	for(i=1;i<=N;i++)
	{
		cout<<vect[i]<<"\n";
	}
	return 0;
}