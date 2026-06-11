#include<iostream>

using namespace std;

int main(){

int a=1,x=0;

while(1){

cin >> x;

if(x == 0) break;

else{

cout << "Case" << " " << a << ":" << " " << x << "\n";

}

a++;

}

return 0;

}