#include <iostream>
using namespace std;
int main(void){
    int x,x1=0,count=0;
    cin>>x;
    while(true){
        count++;
        x1+=x;
        if(x1%360==0){
            cout<<count<<endl;
            break;
        }
    }
    
    
}
