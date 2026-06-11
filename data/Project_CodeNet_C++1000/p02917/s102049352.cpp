#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> b(N-1);
  for(int i=0;i<N-1;i++)
    cin>>b.at(i);
  vector<int> ans(N);
  ans.at(0)=b.at(0);
  for(int i=1;i<N-1;i++)
    ans.at(i)=min(b.at(i-1),b.at(i));
  ans.at(N-1)=b.at(N-2);
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=ans.at(i);
  }
  cout<<sum<<endl;
}
