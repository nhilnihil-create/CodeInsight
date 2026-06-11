#include<bits/stdc++.h>
using namespace std;

long long gcd(int i,int j,int k)
{
    int first=__gcd(i,j);
    int second=__gcd(first,k);

    return second;
}

int main()
{
    int n;
    cin>>n;
    int sum=0;

    for(int a=1;a<=n;a++)
        for(int b=1;b<=n;b++)
        for(int c=1;c<=n;c++)

        sum+=gcd(a,b,c);

    cout<<sum<<endl;
    exit(0);
}






















/*
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a%b==0)
        return b;

    return gcd(b,a%b);
}

int main()
{
    int k;
    cin>>k;
    int sum=0;

    for(int i=1; i<=k; i++)

        for(int j=1; j<=k; j++)

            for(int l=1; l<=k; l++)

                sum+=gcd(gcd(j,l),i);

    cout<<sum<<endl;
    exit(0);

}
*/
