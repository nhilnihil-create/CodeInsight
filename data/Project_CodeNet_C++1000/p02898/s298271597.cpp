#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
    // Your code here!
    int n,k,h,o=0;
    cin>>n>>k;
    for(int z=1;z<=n;z++){
        cin>>h;
        if(k<=h){
            o++;
        }
    }
    cout<<o<<endl;;
}