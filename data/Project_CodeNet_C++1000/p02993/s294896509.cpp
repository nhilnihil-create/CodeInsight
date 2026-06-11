#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    
    string s1;
    getline( cin, s1 );
    int n1 = s1.size();
    
    int n=0;
    for( int i = 0; i < n1-1; i++ ){
        if( (int)s1[i+1]==(int)s1[i] ) n++;
    }

    if( n >= 1 ) {
        cout << "Bad" << endl;
    }
    else {
        cout << "Good" << endl;
    }
      
    return 0;
}
