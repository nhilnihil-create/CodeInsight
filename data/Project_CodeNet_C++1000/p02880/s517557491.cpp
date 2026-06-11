#include<iostream>
using namespace std;

int a,x,y;
bool v;

int main(){
    cin>>a;
    v=false;
    for (int x=1; x<=9;x++){
        for(int y=1;y<=9;y++){
           if (a==x*y){
               v=true;
           }
        }
    }
    if(v){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}
