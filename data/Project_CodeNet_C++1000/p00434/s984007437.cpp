#include<iostream>
using namespace std;

int main(){
    bool st[31];
    for( int i=1; i<=30; i++ ){
        st[i] = false;
    }
    for( int i=0; i<28; i++ ){
        int n;
        cin >> n;
        st[n] = true;
    }
    for ( int i=1; i<=30; i++ ){
        if( !st[i] )
            cout << i << endl;
    }
    return 0;
}