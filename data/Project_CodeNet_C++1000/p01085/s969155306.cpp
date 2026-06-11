#include <bits/stdc++.h>
using namespace std;
vector<int>ansl;
string s;
int main(){
  int M,N_MIN,N_MAX;

  cin >>M>>N_MIN>>N_MAX;
  while(!((M==0)&&(N_MIN==0)&&(N_MAX==0))){
    vector<int> v;
    for(int i = 0;i<M;i++){
      int x;
      cin >>x;
      v.push_back(x);
    }
    int ans = N_MIN-1;
    int gap = v[N_MIN-1]-v[N_MIN];
    for(int i = N_MIN;i <= N_MAX-1;i++){
      int z = v[i]-v[i+1];
      int mx = gap;
      gap = max(gap,z);
      if(mx != gap){
        ans = i;
      }
      if(mx == z){
          ans = i;
      }
    }
    ansl.push_back(ans+1);
    cin >>M>>N_MIN>>N_MAX;
  }

  for(int i = 0;i<(int)ansl.size();i++){
    cout <<ansl[i]<<endl;
  }
  return 0;
}

