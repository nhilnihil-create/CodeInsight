#include<iostream>
#include<string>
using namespace std;

int main(){
    int dice[7],a;
    string order;
    for(int i=1;i<7;i++){
        cin>>dice[i];
    }
    cin>>order;
    
    for(int i=0;i<order.length();i++){
        if(order[i]=='E'){
            a=dice[1];
            dice[1]=dice[4];
            dice[4]=dice[6];
            dice[6]=dice[3];
            dice[3]=a;
        }
        else if(order[i]=='N'){
            a=dice[1];
            dice[1]=dice[2];
            dice[2]=dice[6];
            dice[6]=dice[5];
            dice[5]=a;
        }
        else if(order[i]=='S'){
            a=dice[1];
            dice[1]=dice[5];
            dice[5]=dice[6];
            dice[6]=dice[2];
            dice[2]=a;
        }
        else if(order[i]=='W'){
            a=dice[1];
            dice[1]=dice[3];
            dice[3]=dice[6];
            dice[6]=dice[4];
            dice[4]=a;
        }
    }
    cout<<dice[1]<<endl;
}