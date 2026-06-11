#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,N;
  map<int,vector<int>>p;
  cin >> X >> N;
  for(int i=0;i<N;i++)
  {
    int j;
    cin >> j;
    p[abs(X-j)].push_back(j);
  }
  int d[2]={-1,1};
  for(int l=0;l<100;l++){
    if(p[l].size()==2) continue;
    if(p[l].size()==0){
      cout << X - l << endl;
      return 0;
    }

    for(int m:p[l])
    {
      for(int n:d)
      {
        int r=l*n+X;
        if(m!=r)
        {
          cout << r << endl;
          return 0;
        }
      }	
    }
  }
}
