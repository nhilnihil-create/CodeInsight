#include <iostream>

void PrintWallLine( int length ){
    using namespace std;

    for( int i = 0; i < length; ++i ){
        cout << '#';
    }
    cout << endl;
}

void PrintRoomLine( int length ){
    using namespace std;
    
    for( int i = 0; i < length; ++i ){
        if( i == 0 || i == length-1 ){
            cout << '#';
        } else {
            cout << '.';
        }
    }
    cout << endl;
}

void PrintArea( int H, int W ){
    using namespace std;

    for( int i = 0; i < H; ++i ){
        if( i == 0 || i == H-1 ){
            PrintWallLine( W );
        } else {
            PrintRoomLine( W );
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