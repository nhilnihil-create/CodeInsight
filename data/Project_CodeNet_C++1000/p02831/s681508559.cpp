#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=2;i<=a&&i<=b;i++)
        if(a%i==0 && b%i==0){
            ans*=i;
            a/=i;
            b/=i;
            i-=1;
        }    
    cout<<(long long)ans*a*b<<endl;
}
