#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof()

int main()
{

  int n,mini=INT_MAX; cin>>n;
  int a[n];

  for(int i=0;i<n;i++)
    cin>>a[i];



 for(int w=0;w<n;w++)
 {   int sum=0,sum1=0;
    for(int j=0;j<n;j++){
        if(j<w)
          sum += a[j];
        else
          sum1 += a[j];
    }
    long long diff = abs(sum-sum1);

      if(diff < mini)
        mini = diff;
 }

  // cout<<"the minimum sum difference in the array is"<<endl;
  cout<<mini<<endl;

  return 0;
}

