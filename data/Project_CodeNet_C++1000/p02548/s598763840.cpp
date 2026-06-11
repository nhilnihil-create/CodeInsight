#include <iostream>//bit DP
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
priority_queue<long>p;
int main()
{
  long long n;
  cin>>n;
  long long ans=0;
  for(int i=1;i<n;i++){
    ans+=(n-1)/i;
  }
  cout<<ans<<endl;
}
