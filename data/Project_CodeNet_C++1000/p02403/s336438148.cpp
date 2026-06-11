
#include<iostream>
using namespace std;

int main(){
    int x,y;
    while(cin>>y>>x){
        if(x!=0||y!=0){
            for(int i=0;i<y;i++){
                for(int j=0;j<x;j++){
                    cout<<'#';
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    
}
