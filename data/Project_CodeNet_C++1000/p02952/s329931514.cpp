#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a,count=0,count2=0;
    cin>>a;
    int b=a;
    while(b!=0){
        int rem=b%10;
        count++;
        b=b/10;
    }
    if(count==1){
        for(int i=1;i<=a;i++){
            count2++;
        }
        cout<<count2<<endl;
    }
    else if(count==2){
        cout<<9<<endl;
    }
    else if(count==3){
        for(int i=100;i<=a;i++){
            count2++;
        }
        cout<<count2+9<<endl;
    }
    else if(count==4){
        for(int i=1000;i<=a;i++){
            count2++;
        }
        cout<<909<<endl;
    }
    else if(count==5){
        for(int i=10000;i<=a;i++){
            count2++;
        }
        cout<<count2+909<<endl;
    }
    else if(count==6){
        cout<<90909<<endl;
    }
    return 0;
}
