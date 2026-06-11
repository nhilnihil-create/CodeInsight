#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,a,b,c,d,sum=0,array[100000+10],cnt=0,ans=INT_MIN,i,j;
    string str,ptr;
    cin>>str>>ptr;
    for(i=0;i<str.length();i++)
    {
        if(str[i]==ptr[i])
            cnt++;
    }
    cout<<cnt<<endl;
}
