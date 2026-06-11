#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    // Your code here!
    int a,b;
    cin>>a>>b;
    a-=b*2;
    if(a<=0){
        cout<<"0"<<endl; 
    }else{
        cout<<a<<endl; 
    }
}
