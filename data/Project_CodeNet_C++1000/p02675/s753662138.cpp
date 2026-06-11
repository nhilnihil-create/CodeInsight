#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    if(a%10==3) printf("bon");
    else if(a%10==0||a%10==1||a%10==6||a%10==8) printf("pon");
    else printf("hon");
    return 0;
}