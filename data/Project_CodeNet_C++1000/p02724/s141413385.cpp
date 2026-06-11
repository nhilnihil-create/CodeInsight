#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int n,c=0,d=0;
    cin>>n;
    while(n>0)
    {
        if(n%500==0)
        {
            n-=500;
            c++;
        }
        else if(n%5==0)
        {
            n-=5;
            d++;
        }
        else if(n%100==0)
        {
            n-=100;
        }
        else if(n%50==0)
        {
            n-=50;
        }
        else if(n%10==0)
        {
            n-=10;
        }

        else
        {
            n--;
        }
    }
    cout<<c*1000+d*5<<endl;



    return 0;
}
