#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
int c[200000];
int main()
{      


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     int n;
     cin>>n;
     int x;
     for(int i=1;i<n;i++)
      {
        cin>>x;
        c[x]++;
      }
      for(int i=1;i<=n;i++)
        cout<<c[i]<<endl;

      return 0;
 }       
