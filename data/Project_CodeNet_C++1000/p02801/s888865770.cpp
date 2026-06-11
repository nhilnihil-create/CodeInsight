#include <iostream>

using namespace std;

int main()
{
char  a[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char x;
cin>>x;
for(int i=0;i<26;i++)
{
if (x==a[i])
{
    cout<<a[i+1];
}

}
    return 0;
}