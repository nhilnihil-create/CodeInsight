#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int H; int N; cin>>H>>N;
  vector<int> S(N);
  for(int i=0; i<N; i++){
    cin>>S.at(i);
    H-=S.at(i);
  }
  if(H<=0)
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
