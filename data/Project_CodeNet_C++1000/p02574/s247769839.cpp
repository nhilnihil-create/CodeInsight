#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long int ll;
vector<int>prime;
void sieve()
{
    vector<bool>visit(1000001,true);
    for(int i=2;i*i<=1000000;i++)
    {
        if(visit[i])
        {
            for(int j=i*i;j<=1000000;j+=i)
            {
                visit[j]=false;
            }
        }
    }
    for(int i=2;i<=1000000;i++)
    {
        if(visit[i])
        {
            prime.push_back(i);
        }
    }
}
int present[1000001]={0};
int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        {
            cin>>arr[i];

        }

        bool coprime=true;
    for(int i=0;coprime&&i<n;i++)
    {
        int val = arr[i];



            for(int j=1;j*j<=val;j++)
            {
                if(val%j==0)
                {
                    int q = val/j;
                   if(present[j]!=0||present[q]!=0)
                    {
                        coprime=false;
                        break;
                    }
                    else
                    {
                        if(j==1)
                        {
                            if(q!=1)
                            present[q]=1;
                        }
                        else
                            present[j]=present[q]=1;
                    }
                }
            }



    }
    if(coprime)
    {
        cout<<"pairwise coprime\n";
    }
    else
    {
        int gcd=0;
        for(int i=0;i<n;i++)
        {
            gcd = __gcd(gcd,arr[i]);
        }
        if(gcd==1)
        {
            cout<<"setwise coprime\n";
        }
        else
        {
            cout<<"not coprime\n";
        }
    }
}
