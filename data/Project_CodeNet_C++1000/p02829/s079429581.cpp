#include <iostream>

using namespace std;

int main()
{
int a;
int b;
cin>>a;
cin>>b;
if(a == 1 && b==2 || a==2 &b==1){

    cout<<"3";
} else if(a == 2 && b==3 || a==3 &b==2){
cout<<"1";
} else{
cout<<"2";
}
}
