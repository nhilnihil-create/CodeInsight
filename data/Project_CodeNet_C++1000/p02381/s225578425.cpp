#include<iostream>
#include<math.h>
#define MAX 1000
using namespace std;

int main()
{
	int n,i=0,j=0;
	int S[MAX]={0};
	double a=0.0,m=0.0,temp=0.0;

	while(1)
	{
		cin >> n;
		
		if(n == 0 ) break;

		for(j=0;j<n;j++)
		{
			cin >> S[i] ;
			m = m + S[i] ;
			i++;
		}

	m = m / n ;

	for(i=0;i<n;i++)
	{
		temp = temp + (S[i] - m)*(S[i] - m) ;
	}

	a = temp / n ;

	a = sqrt(a);

	cout << a << endl;

	a = 0.0;
	m = 0.0;
	temp = 0.0;
	i=0;

	}

	return 0;
}