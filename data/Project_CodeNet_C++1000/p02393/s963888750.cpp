#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    using namespace std;

    int a, b, c = 0;
    cin >> a >> b >> c;
    
    vector<int> vec;
    vec.push_back( a );
    vec.push_back( b );
    vec.push_back( c );

    sort( vec.begin(), vec.end() );

    for( unsigned int i = 0; i < vec.size(); ++i ){
        cout << vec[i];
        if( i != vec.size() - 1 ){
            cout << ' ';
        }else{
            cout << endl;
        }
    }
}