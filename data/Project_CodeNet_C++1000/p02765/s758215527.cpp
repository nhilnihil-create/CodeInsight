#include <iostream>
using namespace std;
int main(void){
    int n,r;
    cin>>n>>r;
    if(n>=10){
        cout<<r<<endl;
    }else{
        r+=100*(10-n);
        cout<<r<<endl;
    }
}