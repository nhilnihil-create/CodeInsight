#include<iostream>
using namespace std;

int main(){
int x,y,z;
cin  >> x >> y >> z;
if (x >= y &&  y >=  z ){
  cout  <<  z  << " " << y << " " << x << endl;
} else if ( x <= y && y  <= z ){
  cout << x << " " << y << " " << z << endl;
} else if (x >= z && z >= y) {
  cout << y <<" " << z << " " << x << endl;
}  else if (x <= z && z <= y){
  cout << x << " " << z << " "  << y << endl;
} else if (z <= x && x <= y){
  cout << z << " " << x << " " << y << endl;
} else {
  cout << y << " " << x << " " << z << endl;
}
return 0;}

