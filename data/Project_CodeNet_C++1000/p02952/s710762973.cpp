#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int x,count=0,count1=0;

    cin >> x;

    int y = x;

    while(y!=0){

        int rem=y%10;

        count++;

        y=y/10;
    }

    if(count==1){

        for(int i=1;i<=x;i++){

            count1++;
        }
        cout<<count1<<endl;
    }

    else if(count==2){

        cout<<9<<endl;
    }
    else if(count==3){

        for(int i=100;i<=x;i++){

            count1++;
        }
        cout<<count1+9<<endl;
    }
    else if(count==4){

        for(int i=1000;i<=x;i++){

            count1++;
        }
        cout<<909<<endl;
    }
    else if(count==5){

        for(int i=10000; i<=x; i++){

            count1++;
        }
        cout<<count1+909<<endl;
    }
    else if(count==6){

        cout<<90909<<endl;
    }
    return 0;
}

