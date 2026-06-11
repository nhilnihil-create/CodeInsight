#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    int num=0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        num+=a[i];
    } 
    if(n-num>=0)
    cout<<n-num<<endl;
    else
    cout<<-1<<endl;
    return 0;
}