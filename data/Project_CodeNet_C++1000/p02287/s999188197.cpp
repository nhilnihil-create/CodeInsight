#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
#define CLR(a)     memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)    cerr << #x << " = " << (x) << endl;//debug
#define debug(x)   cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define EPS        1e-10//sample:if((double)>=(double)+EPS)
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

using namespace std;
#define MAX 100000


int main(){
  int n,A[MAX]={};
  cin>>n;
  for(int i=1;i<=n;i++)cin>>A[i];
  for(int i=1;i<=n;i++){
    cout<<"node "<<i<<": key = "<<A[i];
    if(i/2>=1)cout<<", parent key = "<<A[i/2];
    if(2*i<=n)cout<<", left key = "<<A[2*i];
    if(2*i+1<=n)cout<<", right key = "<<A[2*i+1];
    cout<<", "<<endl;
  }
  return 0;
}
