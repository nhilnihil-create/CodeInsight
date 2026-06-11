#include<iostream>
#include<string>
using namespace std;
int main ()
{
    int n;
    int c=0;
    cin>>n;
    char ch [n];
    cin>>ch;
    for (int i=0; i<n; i++)
    {
        if(ch[i]=='A' && ch[i+1]=='B' && ch[i+2]=='C' )
            c++;
    }
    cout<<c<<endl;
    return 0;
}
