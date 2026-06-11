#include <iostream>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    int i,j;
    while(h>=3&&w>=3){
        for(i=1;i<=w;i++){
            cout<<"#";
        }
        cout<<"\n";
        for(j=1;j<=h-2;j++){
            cout<<"#";
            for(i=1;i<=w-2;i++){
                cout<<".";
            }
            cout<<"#\n";
        }
        for(i=1;i<=w;i++){
            cout<<"#";
        }
        cout<<"\n\n";
        cin>>h>>w;
    }
}