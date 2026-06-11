#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
    int n,k;
    cin>>n>>k;
    int p[n];
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> sum(n);
    for(int i=0;i<n;i++)
    {
        sum[i]=(p[i]*(p[i]+1))/2;
    }
    double calc=0,ans=-1.00;;
    for(int i=0;i<=n-k;i++)
    {
        
        if(!i)
            {

             for(int j=0;j<k;j++)
             {
                calc+=((double)sum[i+j])/p[i+j];
               
             }
              ans=max(ans,calc);
             // cout<<calc<<endl;
            }
            else
            {
                calc+=((double)sum[i+k-1])/p[i+k-1];
               // calc+=sum[i+k];
               calc-=((double)sum[i-1])/p[i-1];
               // calc-=sum[i-1];
                ans=max(ans,calc);

            }

            

        }
        printf("%.7f",ans);
       // cout<<setprecision(7)<<ans<<endl;

    }


