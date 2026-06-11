#include <cstdio>

//  1240380 C++	00.00 s	1040 KB	1006 B	2015-03-08 19:10
// cl /EHsc xxx.cpp
int main(int argc, char *argv[])
{
	int n;
	scanf("%d ", &n);
	
	int cards[4][13] = {0};
	
	int t = n;
	while (t)
	{
		//scanf("%c %d ", &c0, &v);
		char buff[1024] = {0};
		gets(buff);
		//printf("%s\n", buff);
		
		char c0;
		int v;
		sscanf(buff, "%c %d", &c0, &v);
		switch (c0)
		{
		case 'S':
			cards[0][v-1] = 1;
			break;
		case 'H':
			cards[1][v-1] = 1;
			break;
		case 'C':
			cards[2][v-1] = 1;
			break;
		case 'D':
			cards[3][v-1] = 1;
			break;
		default:
			break;
			//printf("c0=%d\n", c0);
		}
		t--;
		//printf("!!!!!!t=%d\n", t);
	}
	
	char cc[4] = {'S' ,'H', 'C', 'D'};
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 13; c++)
		{
			if (cards[r][c] == 0)
			{
				printf("%c %d\n", cc[r], c+1);
			}
		}
	}
	
	return 0;
}