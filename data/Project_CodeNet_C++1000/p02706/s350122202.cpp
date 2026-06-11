#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main()
{




    long long ai,t,n,a,A,sum=0,b,B,c=0,k,e,f,g;



    cin >> a >> b;

    for(long long i=0;i<b;i++)
    {
        cin >> n;
        sum+=n;

    }

    if(sum == a)
        cout << "0";
    else if(sum > a)
        cout << "-1";
    else
    {
        cout << a-sum;

    }







return 0;
}