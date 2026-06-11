#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   for(int i=0;i<(n);++i)
#define SORT(c)    sort((c).begin(),(c).end())
const double EPS = 1e-10;//sample:if((double)>=(double)+EPS)
#define CLR(a) memset((&a), 0 ,sizeof(a))//clear memory
#define dump(x)  cerr << #x << " = " << (x) << endl;//debug
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//cin,cout release
//std::cin.tie(0);
//ios::sync_with_stdio(false);

using namespace std;

int partition(int A[], int p, int r){
  int x=A[r], i=p-1;
  for(int j=p;j<r;j++)
    if(A[j]<=x)swap(A[++i],A[j]);
  swap(A[i+1],A[r]);
  return i+1;
}

int main(){
  int n,A[100000];
  cin>>n;
  for(int i=0;i<n;i++)cin>>A[i];
  int a=partition(A,0,n-1);
  for(int i=0;i<n;i++){
    if(i!=0)cout<<" ";
    if(i==a)cout<<"[";
    printf("%d",A[i]);
    if(i==a)cout<<"]";
  }
  printf("\n");
  return 0;
}

