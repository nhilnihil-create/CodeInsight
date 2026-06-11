#include<iostream>
using namespace std;
int main(){
int s[31],m;
for(int i=1;i<=28;i++){
cin >> m;
s[m]=1;
}
for(int i=1;i<=30;i++){
if(s[i]!=1){
cout << i << endl;
}
}
return 0;
}
