#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;cin>>n;
    if(n%2==0){
    n/=2;
    cout<<n-1;
    }
    else{
        cout<<n/2;
    }
}
