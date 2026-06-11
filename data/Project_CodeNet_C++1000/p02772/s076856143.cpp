#include<iostream>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0)
            if(a[i]%3!=0&&a[i]%5!=0)
                ans=1;
    }
    if(ans==0)
        cout<<"APPROVED\n";
    else
        cout<<"DENIED\n"; 
}