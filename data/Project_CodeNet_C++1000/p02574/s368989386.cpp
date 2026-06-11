#include<bits/stdc++.h>
using namespace std;
int flag=0;
vector<int> hasfac(1000002,0);

void calcfac(int x)
{
    if(flag==1)
        return ;
    for(int i=1;i*i<=x;i++)
    {
        int a,b;
        if(x%i==0)
        {

                a=i;
                b=x/i;

            if(a==b){
                a=i;
                b=1;
            }


        if(a!=1)
        {

        if(hasfac[a]!=0)
        {
            flag=1;
            return;
        }

            hasfac[a]++;
        }

        if(b!=1)
        {
           if(hasfac[b]!=0)
            {
                flag=1;
                return;
            }

                hasfac[b]++;

        }
    }

}
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    calcfac(arr[0]);
    int gcd=arr[0];
    for(int i=1;i<n;i++)
    {

        calcfac(arr[i]);
        gcd=__gcd(gcd,arr[i]);

    }
    if(flag==0)
        cout<<"pairwise coprime";
    else if(gcd==1)
        cout<<"setwise coprime";
    else
        cout<<"not coprime\n";

}
