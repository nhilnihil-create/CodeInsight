  #include <iostream>
using namespace std;
int main(){
	int w , h , x , y , z ;
	while ( 1 )
	{
		cin >> h >> w ;
		z = 1 ;
		if ( w == 0 && h == 0 ) break ;
	while ( z <= h ){
		for ( x = 1 ; x <= w ; x ++ )
			cout << "#" ;
			z ++ ;
			cout << endl;
	}
	cout << endl;
}
}