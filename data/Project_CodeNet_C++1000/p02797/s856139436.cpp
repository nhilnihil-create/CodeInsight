#include <iostream>
using namespace std;

int main(void){
    int n,k,s;
    cin>>n>>k>>s;
    int AMAX = 1000000000;
    for(int i=0;i<k;i++) cout<<s<<" ";
    s = s % AMAX + 1;
    for(int i=0;i<n-k;i++) cout<<s<<" ";
    cout<<endl;
}