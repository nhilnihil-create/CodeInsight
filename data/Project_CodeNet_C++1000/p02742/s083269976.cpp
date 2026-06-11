#include <iostream>
using namespace std;
int main(void){
    long long h,w;
    cin>>h>>w;
    if (h==1 |w==1){
        cout<<1;
    }
    else{
        cout<<((h*w+1)/2);
    }
}