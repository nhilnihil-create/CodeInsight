#include<iostream>
#include<math.h>
#define MAX 1000
using namespace std;

int main()
{
	int n,j=0;
	int S[MAX]={0};
	double a=0.0,m=0.0,temp=0.0;

	while(1)
	{
		a = 0.0;
		m = 0.0;
		temp = 0.0;
		
		cin >> n;
		
		if(n == 0 ) break;

		for(int i=0;i<n;i++)
		{
			cin >> S[i] ;
			m = m + S[i] ;
		}

		m = m / n ;

		for(int i=0;i<n;i++)
		{
			temp = temp + (S[i] - m) * (S[i] - m) ;
		}

		a = temp / n ;

		a = sqrt(a);

		cout << a << endl;

	}

	return 0;
}