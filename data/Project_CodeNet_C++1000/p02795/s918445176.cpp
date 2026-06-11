#include <bits/stdc++.h>
 
using namespace std;
const int N = 4e5 + 5;
typedef long long ll;
const ll inf=1e15;
#define pb push_back
const int INF=(0x3f3f3f3f);
 
//#define _

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
#ifdef _
  //freopen("text.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  const clock_t begin_time=clock();
#endif  
  
  
  int H,W,N;
  cin>>H>>W>>N;
  int mx=max(H,W);
  cout<<ceil((long double)N/mx)<<'\n';
  
  
#ifdef _
  //cout<<"\n\n\n\n\n\n\n\n\n\n\n";
  //cout<<float(clock()-begin_time)/CLOCKS_PER_SEC;
  cout<<fixed<<setprecision(45)<<double(clock()-begin_time)/CLOCKS_PER_SEC;
#endif
}








