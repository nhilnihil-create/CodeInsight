#include <iostream>

void PrintCheckFirstSharp( int length ){
    using namespace std;

    for( int i = 0; i < length; ++i ){
        if( i % 2 == 0 ){
            cout << '#';
        } else {
            cout << '.';
        }
    }
    cout << endl;
}

void PrintCheckFirstDot( int length ){
    using namespace std;
    
    for( int i = 0; i < length; ++i ){
        if( i % 2 == 0 ){
            cout << '.';
        } else {
            cout << '#';
        }
    }
    cout << endl;
}

void PrintArea( int H, int W ){
    using namespace std;

    for( int i = 0; i < H; ++i ){
        if( i%2 == 0){
            PrintCheckFirstSharp( W );
        } else {
            PrintCheckFirstDot( W );
        }
    }
    cout << endl;
}

int main(){
    using namespace std;

    while( true ){
        int H = 0;
        int W = 0;
        cin >> H >> W;

        if( H == 0 && W == 0 ){ break; }

        PrintArea( H, W );
    }

    return 0;
}