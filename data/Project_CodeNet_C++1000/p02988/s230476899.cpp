#include<bits/stdc++.h>
using namespace std;
#define f for(int i=0;i<n;i++)
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    f
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    int count=0;
      for(int i=1;i<n-1;i++)
      {
          if(v[i-1]<v[i]&&v[i]<v[i+1])
         count++;
         if(v[i-1]>v[i]&&v[i]>v[i+1])
         count++;
      }
cout<<count<<endl;


    return 0;
}

