#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll ;
char a[30]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main()
{
    ll n,x;
    string s;
    cin>>n;
    while(n)
    {
        x=n%26;
        if(x==0)x=26;
        s+=a[x-1];
        n=(n-1)/26;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}