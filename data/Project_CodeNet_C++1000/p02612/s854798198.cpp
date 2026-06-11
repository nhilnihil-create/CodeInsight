#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%1000)
    {  int i = n/1000;
        while(n>i*1000)
        {
            i++;
        }
        cout<<i*1000-n<<endl;
    }
    else
    cout<<0<<endl;
    return 0;
}