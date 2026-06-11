#include<iostream>
using namespace std;
int main(){
    long n,k,t;
    cin>>n>>k;
    t=n%k;
    cout<<min(t,k-t)<<endl;
return 0;
}
