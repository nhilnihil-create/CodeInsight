#include <iostream>
using namespace std;
int main(){
    int k,a,b;
    cin>>k>>a>>b;
    int rem = a%k;
    if(rem!=0)
        rem=k-rem;
    if(rem>b-a){
        cout<<"NG"<<endl;
    }else{
        cout<<"OK"<<endl;
    }
    return 0;
}