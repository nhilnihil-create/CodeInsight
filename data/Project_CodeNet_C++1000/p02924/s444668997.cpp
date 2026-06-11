#include<bits/stdc++.h>
using namespace std;
#define ll "%I64d"
const int max1=100010;
//long long a[max1],b[max1];
int main()
{
    long long n,a=0,b;
    cin>>n;
    if(n==1)
    {
        cout<<0<<"\n";
    }
    else
    {
        vector<long long int>s1;
        long long t1;
        t1=((n-1)*n)/2;
        /*for(long long i=1; i<n; i++)
        {
            a+=i;
            s1.push_back(a);
        }
        int h=s1.size()-1;
*/
        cout<<t1<<"\n";
    }

}

