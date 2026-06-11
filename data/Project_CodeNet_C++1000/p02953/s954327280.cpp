#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> H(N);
  for(int &i:H)
    cin>>i;
  bool bo=false;
  for(int i=N-2;i>=0;i--){
    if(H[i]>H[i+1])
      if(H[i]-H[i+1]>1){
        cout<<"No"<<endl;
        return 0;
      }else
        H[i]--;
  }
  cout<<"Yes"<<endl;
}