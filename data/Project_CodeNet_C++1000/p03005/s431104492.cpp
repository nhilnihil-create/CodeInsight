#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    if(k<2 || n<k)
    cout<<"0"<<endl;
    else{
    cout<<n-k<<endl;
    }
return 0;
}