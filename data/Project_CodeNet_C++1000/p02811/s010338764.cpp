#include <iostream>
using namespace std;
int main(void){
    int k, x;
    cin>>k>>x;
    int ans=500*k;
    if (ans>=x) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}