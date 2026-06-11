#include<iostream>
#include<string>
#include<time.h>
#include<random>
using namespace std;

struct Dice{
    int s[6];
    void move(char c){
        int tmp;
        if(c=='N'){
            tmp=s[0];
            s[0]=s[1];
            s[1]=s[5];
            s[5]=s[4];
            s[4]=tmp;
        }
        else if(c=='S'){
            tmp=s[0];
            s[0]=s[4];
            s[4]=s[5];
            s[5]=s[1];
            s[1]=tmp;
        }
        else if(c=='E'){
            tmp=s[0];
            s[0]=s[3];
            s[3]=s[5];
            s[5]=s[2];
            s[2]=tmp;
        }
        else if(c=='W'){
            tmp=s[0];
            s[0]=s[2];
            s[2]=s[5];
            s[5]=s[3];
            s[3]=tmp;
        }
    }
    int get_top(){
        return s[0];
    }
    int get_right(){
        return s[2];
    }
};

int main(){
    Dice dice;
    for(int i=0;i<6;i++)cin>>dice.s[i];
    int n,s0,s1;
    cin>>n;
    srand((int)time(0));
    for(int i=0;i<n;i++){
        cin>>s0>>s1;
        while(true){
            if(dice.s[0]==s0&&dice.s[1]==s1)break;
            int random=rand()%4;
            if(random==0)dice.move('N');
            else if(random==1)dice.move('S');
            else if(random==2)dice.move('E');
            else dice.move('W');
        }
        cout<<dice.get_right()<<endl;
    }

    return 0;
}
