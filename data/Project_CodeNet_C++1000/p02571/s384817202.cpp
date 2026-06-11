#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e3 + 10;
char S[N],T[N];

int main(void)
{
	cin >> S >> T;
	
	int Max = 0;
	
	for(int r = strlen(T) - 1,l = 0; r < strlen(S); l ++ , r ++ )
	{
		int sum = 0;
		
		for(int j = 0 ; j < strlen(T) ; j ++)
		{
			if(S[l + j] == T[j]) sum ++ ;
		}
		
		Max = max(Max,sum);
	}
	
	//cout << Max << endl;
	
	cout << strlen(T) - Max;
	return 0;
}