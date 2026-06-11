#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    string s[200001];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(&(s[0]),&(s[n]));
    int d=1;
    for(int i=0;i<n-1;i++)
    {
        
        if(s[i]!=s[i+1])
        {
            d++;
        }
    }
    cout<<d;
}