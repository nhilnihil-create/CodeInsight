#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

vector<int> calc(string str) {
  vector<int> tmp(str.size(),0);
  tmp[0]=(str[0]=='#')? 0:1;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i]=='#') tmp[i]=0;
    else tmp[i]=tmp[i-1]+1;
  }
  for (int i = str.size()-2; i >= 0; --i)
  {
    if (tmp[i]==0) continue;
    else if (tmp[i+1]>tmp[i]) tmp[i]=tmp[i+1];
  }
  return tmp;
}

int main()
{
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  vector<vector<int>> row(h,vector<int>(w,0));
  vector<vector<int>> col(w,vector<int>(h,0));
  // vector<vector<int>> field(h,vector<int>(w,0));

  for (int i = 0; i < h; ++i) {
    cin>>s[i];
    row[i]=calc(s[i]);
  }

  for (int i = 0; i < w; ++i)
  {
    string str="";
    for (int j = 0; j < h; ++j) str+=s[j][i];
    col[i]=calc(str);
  }
  int ans=0;
  for (int i = 0; i < h; ++i)
  {
    for (int j = 0; j < w; ++j)
    {
      ans = max(ans,row[i][j]+col[j][i]-1);
      // field[i][j]=row[i][j]+col[j][i]-1;
      // cout<<field[i][j]<<" ";
    }
    // cout<<endl;
  }
  cout<<ans<<endl;

}