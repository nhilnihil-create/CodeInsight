/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void st()
{
    cout<<"setwise coprime";
}
 
void pr()
{
     cout<<"pairwise coprime";
}

void no()
{
    cout<<"not coprime";
}
bool primechk[1000007];
map<long long,long long> mp;

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n,i,x,cnt,j,bb=0;
    //preprocess(1000004);
    cin>>n;
    long long arr[n+5];
    for(i=0;i<n;i++){cin>>arr[i];}
    for(i=0;i<n;i++)
    {
        x=arr[i];
        for(j=2;j*j<=x;j++)
        {
            if(x%j==0)
            {
                mp[j]++;
                if(mp[j]==n){no();return 0;}
                else if(mp[j]>1){bb=1;}
                while(x%j==0){x/=j;}
            }
        }
        if(x>=2){mp[x]++;if(mp[x]==n){no();return 0;}else if(mp[x]>1){bb=1;}}
    }
     if(bb){st();}
    else{pr();}
    return 0;
}