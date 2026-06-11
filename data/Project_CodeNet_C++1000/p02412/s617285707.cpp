#include<iostream>
using namespace std;

int main(){
	int n, x, a;
SAIKI:	
	cin >> n >> x;
	if( n == 0 && x == 0 ){ return 0; }
	for( int i = 1; i <= n ; i++ ){ for( int j = 1; j <= n; j++ ){ for( int k = 1; k <= n; k++ ){ if( i > j && j > k && i + j + k == x ){ ++a; } } } }
	cout << a << endl;
	a = 0;
goto SAIKI;

return 0;
}