#include<iostream>
using namespace std;
int main()
{
    unsigned long int n,num[200000]={0},i,value;
    cin>>n;
    for(i=1;i<n;i++){
        cin>>value;
        num[value-1]++;
    }
    for(i=0;i<n;i++){
        cout<<num[i]<<endl;
    }
    return 0;
}
