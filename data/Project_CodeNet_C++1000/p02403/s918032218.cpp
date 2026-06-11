#include <iostream>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    while(h!=0&&w!=0){
        for(int g=1;g<=h;g++){
            for(int i=1;i<=w;i++){
                cout<<"#";
            }
            cout<<"\n";
        }
        cout<<"\n";
        cin>>h>>w;
    }
}