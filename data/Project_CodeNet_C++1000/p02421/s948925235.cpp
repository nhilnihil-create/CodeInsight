#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,i,x=0,y=0;
    string X,Y;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>X>>Y;
        if(X==Y){
            x=x+1;
            y=y+1;
        }else if(X>Y){
            x=x+3;
        }else{
            y=y+3;
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}