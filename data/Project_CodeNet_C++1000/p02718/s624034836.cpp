#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
  speed_up;
  int n, m, cnt = 0, i, sum = 0;
  double x;
  cin>>n>>m;
  int a[n];
  for(i = 0; i<n ; i++)
  {
      cin>>a[i];
      sum+=a[i];
  }
  x = sum/(4.0*m);
  //cout<<x<<endl;
  for(i = 0; i<n; i++)
  {   //cout<<a[i]<<endl;
      if(a[i]>= x)
      {
          cnt++;
          //cout<<cnt<<endl;
      }
      if(cnt == m)
      {
          cout<<"Yes"<<endl;
          return 0;
      }
  }

  cout<<"No"<<endl;




return 0;
}
