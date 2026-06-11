# include <stdio.h>
# include <string.h>
# include <queue>
# include <algorithm>
using namespace std ;

typedef struct Node
{
	int x ;
	int y ;
}NODE ;


int w, h, m ;
NODE N, NN, NNN ;
queue <NODE> que ;
int flag[1010][1010] ;
char route[1010][1010] ;
int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0} ;

bool bounds(NODE p)
{
	if(p.x < 0 || p.y < 0 || p.x >= w || p.y >= h)
		return false ;
	return true ;
}

void bfs(char c)
{
	memset(flag, 0, sizeof(flag)) ;
	flag[N.x][N.y] = 1 ;
	que.push(N) ;
	while(!que.empty())
	{
		NN = que.front() ;
		que.pop() ;
		for(int i = 0; i < 4; i ++)
		{
			NNN.x = NN.x + direction[i][0] ;
			NNN.y = NN.y + direction[i][1] ;
			if(bounds(NNN) && route[NNN.x][NNN.y] != 'X' && flag[NNN.x][NNN.y] == 0)
			{ 
				flag[NNN.x][NNN.y] = flag[NN.x][NN.y] + 1 ;
				que.push(NNN) ;
				if(route[NNN.x][NNN.y] == c)
					N = NNN ;
			}
			
		}
	}
}
int main ()
{
	while(scanf("%d%d%d%*c", &w, &h, &m) != EOF)
	{
		for(int i = 0; i < w; i ++)
			gets(route[i]) ;
		for(int i = 0; i < w; i ++)
		{
			for(int j = 0; j < h; j ++)
			{
				if(route[i][j] == 'S')
				{
					N.x = i ;
					N.y = j ;
				}
			}
		}
		int sum = 0 ;
		for(int i = 1; i <= m; i ++)
		{
			bfs(i + '0') ;
			sum += flag[N.x][N.y] - 1 ;	
		}
		printf("%d\n", sum) ;
	}

	return 0 ;
}