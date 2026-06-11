#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<char>>&hyo,int n,int m){
  vector<int>delh;
  vector<int>delw;
  bitset<6>a=n;
  bitset<6>b=m;
  int ret=0;
  for(int i=0;i<hyo.size();i++){
    for(int j=0;j<hyo.at(0).size();j++){
      if(a.test(i)&&b.test(j)&&hyo.at(i).at(j)=='#')
        ret++;
    }
  }
  return ret;
}

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  vector<vector<char>>hyo(h,vector<char>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin >> hyo.at(i).at(j);
  int ans=0;
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      if(check(hyo,i,j)==n)
        ans++;
    }
  }
  cout << ans  << endl;
  return 0;
}     