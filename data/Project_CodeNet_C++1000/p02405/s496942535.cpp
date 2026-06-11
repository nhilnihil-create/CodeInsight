#include <iostream>
using namespace std;
int main(){
    int h,w,i,j;
    cin>>h>>w;
    while(h>=1&&w>=1){
        for(i=1;i<=h/2;i++){
            for(j=1;j<=w/2;j++){
                cout<<"#.";
            }
            if(w%2==1){
                cout<<"#";
            }
            cout<<"\n";
            for(j=1;j<=w/2;j++){
                cout<<".#";
            }
            if(w%2==1){
                cout<<".";
            }
            cout<<"\n";
        }
        if(h%2==1){
            for(i=1;i<=w/2;i++){
                cout<<"#.";
            }
            if(w%2==1){
                cout<<"#";
            }
            cout<<"\n";
        }
        cout<<"\n";
        cin>>h>>w;
    }
}