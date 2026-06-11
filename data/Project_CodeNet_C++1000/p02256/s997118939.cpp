#include <iostream>
#include <algorithm>
using namespace std;


int main()
{

    int a , b , result = 0 , ab;
    
    cin >> a >> b;
    if( 1 < a && a < b ){
	ab = b % a;
	for( int i = 1; i <= ab; i++ ){
	    if( ab % i == 0 && a % i == 0 )
		result = max(i,result);
	}
    } else if(1 < b && b < a ){
	ab = a % b;
	//	cout << ab << endl;
	for( int i = 1; i <= ab; i++ ){
	    if( ab % i == 0 && b % i == 0 )
		result = max(i,result);
	}
    }else if( a == b ) result = a;
    
    

    cout << result << endl;
    
    return 0;
}