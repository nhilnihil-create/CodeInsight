#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin>>N;

  vector<long> d1(N);
  vector<long> d2(N);

  for(int i=0;i<N;i++){
    cin>>d1[i]>>d2[i];
    }
    long ans=0;
for(int i=0;i<N-2;i++){
  if(d1[i]==d2[i]&&d1[i+1]==d2[i+1]&&d1[i+2]==d2[i+2]){
    cout<<"Yes"<<endl;
    return 0;
  }
}

cout<<"No"<<endl;
}
