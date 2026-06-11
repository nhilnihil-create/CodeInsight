
#include <iostream>
using namespace std;

int main(void)
{
	while(1)
	{
		int N, M;
		int currX=10, currY=10;
		bool jem[21][21]={false,};

		cin >> N;
		if(N==0)break;
		
		for(int i=0; i<N; i++)
		{
			int x, y;
			cin >> x >> y;
			jem[x][y] = true;
		}
	
		cin >> M;
		for(int i=0; i<M; i++)
		{
			char d;
			int  l;
			cin >> d >> l;
			
			int  mvx, mvy;
			switch(d)
			{
			case 'N': mvx =  0; mvy = +1; break;
			case 'E': mvx = +1; mvy =  0; break;
			case 'W': mvx = -1; mvy =  0; break;
			case 'S': mvx =  0; mvy = -1; break;
			}

			for(int j=0; j<l; j++)
			{
				currX += mvx;
				currY += mvy;
				jem[currX][currY] = false;
			}
		}
		
		bool ans=true;
		for(int i=0; i<=20; i++)
		{
			for(int j=0; j<=20; j++)
			{
				if(jem[i][j])
				{
					ans = false;
					break;
				}
			}
			if(ans == false)break;
		}
		if(ans) cout << "Yes" << endl;
		else    cout << "No"  << endl;
	}

	return 0;
}