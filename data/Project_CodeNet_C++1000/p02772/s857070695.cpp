#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,con=0;
    cin>>a;
    for(int z=0;z<=a;z++){
        cin>>b;
        if(b%2==0){
            if(b%3==0){
            }else{
                if(b%5==0){
                }else{
                    cout<<"DENIED"<<endl;
                    con++;
                    break;
                }
            }
        }
    }
    if(con==0){
        cout<<"APPROVED"<<endl;
    }
}