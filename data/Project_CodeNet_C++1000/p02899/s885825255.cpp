#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
 vector<int> a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
   vector<int> b(N);
  for(int i=0;i<N;i++)
    b.at(a.at(i)-1)=i;
  for(int i=0;i<N;i++)
    cout<<b.at(i)+1<<' ';
}