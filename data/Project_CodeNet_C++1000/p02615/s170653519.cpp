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
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    long a;cin>>a;
    p.push(a);
  }
  long ans=0;
  if(n%2==0){
    ans+=p.top();
    p.pop();
    for(int j=1;j<=n/2-1;j++){
      ans+=2*p.top();
      p.pop();
    }
  }else{
    ans+=p.top();
    p.pop();
    for(int j=1;j<=n/2-1;j++){
      ans+=2*p.top();
      p.pop();
    }
    ans+=p.top();
  }
  cout<<ans<<endl;
}
