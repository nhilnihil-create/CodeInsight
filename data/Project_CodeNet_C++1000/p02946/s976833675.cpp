#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,k,j;
    cin>>a>>b;
    k=a+b;
    j=b-a+1;
    for(int z=j;z<k;z++){
        if(z<1000000||z>-1000000){
            cout<<z<<" ";
        }
    }
    cout<<endl;
}
