#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  vector<vector<int>> field(h,vector<int>(w,1));
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      if(i<b&&j<a) field[i][j]=0;
      else if(i>=b&&j>=a) field[i][j]=0;
      cout<<field[i][j];
    }
    cout<<endl;
  }
}