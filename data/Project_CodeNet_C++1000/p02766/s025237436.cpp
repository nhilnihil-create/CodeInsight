#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,k,i=1;
    cin>>n>>k;
    while(n>=k){ 
        n=n/k;
        i++;
    }
    cout<<i<<endl;
}