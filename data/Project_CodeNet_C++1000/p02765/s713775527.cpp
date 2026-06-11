#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n, r;
    cin>>n>>r;
    if(10<=n){
        cout<<r<<endl;
        
    }
    else{
        cout<<100*(10-n)+r<<endl;
        
    }
}