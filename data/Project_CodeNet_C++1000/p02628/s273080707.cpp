#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
  int N,K;
  cin>>N>>K;
  int p[N];
  for(int i=0;i<N;i++)
    cin>>p[i];
  sort(p,p+N);
    int min_ans=0;
  for(int i=0;i<K;i++)
  {
    min_ans+=p[i];
  }
  cout<<min_ans<<endl;
  return 0;
}