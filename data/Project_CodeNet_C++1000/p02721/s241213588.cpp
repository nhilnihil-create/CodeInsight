#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	long long N,K,C;
	cin >> N >> K >> C;
	string S;
	cin >> S;
	long long leftcount[N];
	leftcount[0] = 1;
	long long rightcount[N];
	rightcount[N-1] = 1;
	int i;
	int tmp1 = 0;
	int tmp2 = N-1;
	for(i=1;i<N;i++)
	{
		if( (S[i] == 'o') && ((i-tmp1)>=(C+1)) )
		{
			tmp1 = i;
			leftcount[i] = leftcount[i-1] + 1;
		}
		else
		{
			leftcount[i] = leftcount[i-1];
		}
	}
	for(i=N-2;i>=0;i--)
	{
		if( (S[i] == 'o') && ((tmp2-i)>=(C+1)) )
		{
			tmp2 = i;
			rightcount[i] = rightcount[i+1] + 1;
		}
		else
		{
			rightcount[i] = rightcount[i+1];
		}
	}
	long long Rightcount[N];
	long long Leftcount[N];
	Leftcount[0] = 0;
	Rightcount[N-1] = 0;
	for(i=1;i<N;i++)
	{
		Leftcount[i] = leftcount[i-1];
	}
	for(i=N-2;i>=0;i--)
	{
		Rightcount[i] = rightcount[i+1];
	}
	for(i=0;i<N;i++)
	{
		if(Rightcount[i] + Leftcount[i] < K)
		{
			cout << i + 1 << endl;
		}
	}
	return 0;
}

			
		
	