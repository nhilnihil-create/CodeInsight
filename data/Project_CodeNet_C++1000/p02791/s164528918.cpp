//BISMILLAHIR RAHMANIR RAHIM

#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;i++)
#define pi acos(-1.00)

using namespace std;



int main()
{
long long int n;
cin>>n;
long long int p[n+1],count=0,i,j,q=0;
for(i=0;i<n;i++)
{
    cin>>p[i];
}
j=p[0];
for(i=0;i<n;i++)
{
    if(j>p[i])
    {
        q++;
        j=p[i];
    }

}
cout<<q+1<<endl;

}

