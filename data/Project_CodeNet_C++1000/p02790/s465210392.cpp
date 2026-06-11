#include <iostream>
using namespace std;
int main(){
 int a, b;
 cin >> a >> b;
 for(int i = 0; i < max(a, b); i++){
   string temp = to_string(min(a, b));
   cout << temp;
   
 }
 return 0; 
}