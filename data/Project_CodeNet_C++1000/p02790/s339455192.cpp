#include <iostream>
#include <string>
using namespace std;
int main(void){
    int a,b;
    string x;
    
    cin >> a >> b;
    
    if(a>=b){
  //      x = to_string(b);
        for(int i=0;i<a;i++) cout << b;
    }
    
    if(a<b){
//        x = to_string(a);
        for(int i=0;i<b;i++) cout << a;
    }
    return 0;
 
}

