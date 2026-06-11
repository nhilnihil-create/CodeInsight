/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){

  long long n; cin>>n;
   int w[n];

 for(int i=0;i<n;i++)
    cin>>w[i];

    long long mini=INT_MAX;

  for(int t=1;t<n;t++)
  {
     long long sum=0,sum1=0;
   for(int i=0;i<n;i++)
    {
     if(i < t)
      sum += w[i];
     else
        sum1+= w[i];
   }

    long long diff = abs(sum-sum1);
     mini = min(mini,diff);

  }


cout<<mini<<endl;

 return 0;
 }