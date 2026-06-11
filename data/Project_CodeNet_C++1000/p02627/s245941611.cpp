#include <iostream>
#include <ctype.h>
using namespace std;
int main(void){
    
    
    char a;
    cin >> a;
    
    bool oomoji = isupper(a);
    
    if(oomoji){
        cout << "A" << endl;
    }
    else{
        cout << "a" << endl;
    }
    
}
