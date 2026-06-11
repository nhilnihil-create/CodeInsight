#include <iostream>
#include <cctype>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string a,b = "";
    while(cin >> a){
        for(int i = 0; i < a.length(); i++){
            if(a[i] >= 'a' && a[i] <= 'z' ){
                a[i] += 'A' - 'a';
            } else if(a[i] >= 'A' && a[i] <= 'Z' ) {
                a[i] -= 'A' - 'a';
            }
        }
    b += a +  " " ;
        
    }
    for(int i = 0; i < b.length() - 1; i ++){
        cout << b[i] ;
    }
    cout << endl;
    return 0;
}
