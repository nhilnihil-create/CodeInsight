#include<iostream>
using namespace std;
int main(){
int a,b;
for (int h = 0;; h++){
cin >> a >> b;
if (a != 0){
for (int i = 0; i < a; i++) {
for (int j = 0; j < b; j++){
if (j > 0 && j < b - 1 && i>0 && i<a-1){
cout << "." ;
}
else{
cout << "#" ;
}
if(j==b-1){
cout<<endl;
}
}
}
cout<<endl;
}
else{
break;
}
}
return 0;
}