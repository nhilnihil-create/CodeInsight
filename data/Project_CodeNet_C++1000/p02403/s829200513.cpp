#include <iostream>

void PrintLine( int length ){
    using namespace std;

    for( int i = 0; i < length; ++i ){
        cout << '#';
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

        for( int i = 0; i < H; ++i ){ PrintLine( W ); }
        cout << endl;
    }

    return 0;
}