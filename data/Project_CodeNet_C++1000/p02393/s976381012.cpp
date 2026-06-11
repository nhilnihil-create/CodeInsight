#include<iostream>
using namespace std;

main(){
int a,b,c;
cin >> a;
cin >> b;
cin >> c;

if(a<=b && a<=c){
cout << a <<" ";
if(b<=c){
cout << b << " "<<c <<"\n";
}
else{
cout << c  <<" "<<b <<"\n";
}
}

else if(b<=a && b<=c){
cout << b <<" ";
if(a<=c){
cout << a<<" "<<c << "\n";
}
else{
cout << c << " "<<a <<"\n";
}
}

else{
cout << c <<" ";
if(a<=b){
cout << a << " "<< b <<"\n";
}
else{
cout << b <<" " <<a<<"\n";
}
}
}