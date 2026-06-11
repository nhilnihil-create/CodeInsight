#include<iostream>

using namespace std;

namespace Original{
    bool isHitachiString( std::string &text ){
        if( text.size() % 2 != 0 ) return false;
        
        for( int i = 0; i < text.size(); i = i + 2 ){
            if( text[i] != 'h' || text[i+1] != 'i' ) return false;
        }
    return true;
    }
}

int main( void ){
    std::string hitachi;
    std::getline( std::cin, hitachi );
    
    if( Original::isHitachiString(hitachi) ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
return 0;
}