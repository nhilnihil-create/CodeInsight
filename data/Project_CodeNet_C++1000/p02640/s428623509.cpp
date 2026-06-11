#include <iostream>
 
using namespace std;
 
int main(){
    int X,Y,a=0;
    cin>>X>>Y;
    for(int i=0;i<=X;i++){
        if((X-i)*2+i*4==Y){
            a=1;
            break;
        }
    }
    if(a==1)printf("Yes\n");
    else printf("No\n");
}