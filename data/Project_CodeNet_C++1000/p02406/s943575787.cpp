#include <iostream>

bool CheckNum( int num, int drawNum, int div, int ans ){
    using namespace std;
    if( num % div != ans ){ return false; }
    cout << " " << drawNum;
    return true;
}

int main(){
    using namespace std;

    int input = 0;
    cin >> input;

    for( int i = 1; i <= input; ++i ){
        int x = i;    
        if( CheckNum( x, i, 3, 0 ) ){ continue; }
        while( x ){
            if( CheckNum( x, i, 10, 3 ) ){ break; }
            x /= 10;
        }
    }

    cout << endl;
   
    return 0;
}