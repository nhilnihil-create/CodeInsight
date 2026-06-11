#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int tm=n-i;
        int a,b;
        for(int i=sqrt(tm);i>0;i--)
        {
          if(tm%i==0)
          {
              b=tm/i;
              a=i;
              if(a!=b)
              {
                  ans+=2;
              }
               else
              {
                  ans++;
              }
          }
        }
    }
    cout<<ans;
}
