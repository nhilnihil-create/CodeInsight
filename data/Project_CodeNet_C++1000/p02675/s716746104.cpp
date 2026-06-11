#include<iostream>
using namespace std;
int main(){
int N;
cin>>N;
int nn=N%10;
if(nn==2||nn==4||nn==7||nn==5||nn==9)
    cout<<"hon"<<endl;
else if(nn==3)
    cout<<"bon";
else
    cout<<"pon";
return 0;
}
