#include <iostream>
using namespace std;

int main(){
    // Your code here!
    int a,b,c;



    while(true){
        cin>>a>>b;
        if(a==0&&b==0){
            break;
        }
        c=0;
        for(int v=1;v<=a;v++){
            for(int l=v+1;l<=a;l++){
                for(int y=l+1;y<=a;y++){
                    if(v+l+y==b)c+=1;
                }
            }
        }        
        cout<<c<<endl;
    }



}

