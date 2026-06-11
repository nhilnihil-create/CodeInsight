#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S, T;
	cin >> S >> T;
	
	int ans = 1005;
	for(int i = 0; i < (int)(S.length()); i++)
	{
		if(i + (int)(T.length()) - 1 >= (int)(S.length()) )
			break;
			
		int changes = 0;
		for(int j = 0; j < (int)(T.length()); j++)
		{
			//printf("S[%d + %d] = %c, T[%d] = %c\n", i, j, S[i + j], j, T[j]);
			if(S[i + j] != T[j])
				changes++;
		}
		
		//printf("%d\n\n", changes);
		ans = min(ans, changes);
	}
	
	printf("%d", ans);
}
