#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std ;
int k,x;
int main(){
    cin >>k>>x;
    if(k*500>=x){
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}