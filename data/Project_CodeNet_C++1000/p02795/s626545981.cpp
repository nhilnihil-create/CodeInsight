#include <iostream>
using namespace std;
int main(void){
    int h,w,n;
    cin>>h>>w>>n;
    cout<<min((n+h-1)/h,(n+w-1)/w);
}
