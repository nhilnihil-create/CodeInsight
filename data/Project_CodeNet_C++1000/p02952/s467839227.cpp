#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,power,sum=0;
    cin>>n;
    string a=to_string(n);
    if(a.size()%2==0)
        power=a.size()/2;
    else
    {
        power=(a.size()-1)/2;
        x=pow(10,a.size()-1);
        sum+=(n-x+1);
    }
    sum+=9*(pow(100,power)-1)/99;
    cout<<sum<<endl;
}


