#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    long s=0;
    long i=0;
    while(i<=n)
    {
        if(i%3==0||i%5==0)
        {

        }
        else
            s+=i;

        i++;

    }
    cout<<s;
}
