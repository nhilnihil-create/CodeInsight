#include<iostream>
#include<cstring>
#include<queue>
using namespace std ;
struct ST
{
	int x ;
	int y ;
	int cnt = 0 ;
} ;
bool came[ 1000 ][ 1000 ] = {{ 0 }} ;
char map[ 1000 ][ 1000 ] ;
int main()
{
	ST m ,s ;
	queue< ST > que ;
	int n ;
	int w ,h ;
	int mx[ 4 ] = { 0 ,0 ,1 ,-1 } ;
	int my[ 4 ] = { 1 ,-1 ,0 ,0 } ;
	cin >> h >> w >> n ;
	char c = '0' ;
	bool a = true ;	
	for( int i = 0 ; i < h ; i++ )
	{
		cin >> map[ i ] ;
		if( a )
		{
			for( int j = 0 ; j < w ; j++ && a )
			{
				if( map[ i ][ j ] == 'S' )
				{
					m.x = j ;
					m.y = i ;
					a = false ;
				}
			}
		}
	}
	que.push( m ) ;
	int cnt = 0 ;
	while( n )
	{
		n-- ;
		c++ ;
		while( !que.empty() )
		{
			m = que.front() ;
			que.pop() ;
			if( came[ m.y ][ m.x ] == 1 )continue ;
			came[ m.y ][ m.x ] = 1 ;
			if( map[ m.y ][ m.x ] == c )
			{
				while( ! que.empty() )
				{
					que.pop() ;
				}
				break ;
			}
			for( int i = 0 ; i < 4 ; i++ )
			{
				if( m.x + mx[ i ] > -1 && m.x + mx[ i ] < w && m.y +  my[ i ] > -1 && m.y + my[ i ] < h )
				{
					s = m ;
					s.x += mx[ i ] ;
					s.y += my[ i ] ;
					s.cnt++ ;
					if( map[ s.y ][ s.x ] != 'X' && came[ s.y ][ s.x ] == 0 )
					{
						que.push( s ) ;
					}
				}
			}
		}
		memset( came ,0 ,sizeof( came ) ) ;
		que.push( m ) ;
	}
	cout << m.cnt << endl ;
	return 0 ;
}