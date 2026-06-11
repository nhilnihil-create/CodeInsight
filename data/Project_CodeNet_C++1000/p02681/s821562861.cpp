#include <bits/stdc++.h>
using namespace std;

int main() {
    string S , T ;
    cin >> S >> T ;
    
    int cnt=0 ;
    
    for( int i=0 ; i< S.size() ; i++ ){
        if( S.at(i) == T.at(i) ){
            cnt++ ;
        }
    }
    
    if( cnt == S.size() ){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}
