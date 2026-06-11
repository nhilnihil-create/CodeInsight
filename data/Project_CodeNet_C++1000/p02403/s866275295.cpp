#include <iostream>

using namespace std;

int main(){
    int H,W;

    
    int i=0;
    int j=0;
    int num=0;
    while(num<1000){
    
    cin>>H>>W;
    if(H!=0 && W!=0){    
        while(i<H){
        
            while(j<W){
                cout<<"#";
                j++;
            }
            cout<<endl;
         j=0;
            i++;
        
        }
        cout<<endl;
        i=0;
    }
    if(H==0 && W==0){
        break;
    }
    
    }
    
    
    
}
