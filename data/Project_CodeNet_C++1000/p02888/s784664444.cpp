#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  int Z=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(p[i]+p[j]>p[N-1]){
        Z+=(N-1-j);
      }
      else{
        int A=lower_bound(p.begin(),p.end(),p[i]+p[j])-p.begin();
        Z+=(A-j-1);
      }
    }
  }
  cout<<Z<<endl;
}