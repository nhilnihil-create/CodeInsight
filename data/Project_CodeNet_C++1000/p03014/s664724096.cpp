#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 
int l[100005] = {};
vector<int> pc(1000000,-1); 
vector<int> f(1000000,-1); 
int lc[2001][2001];
int co[2001][2001][2];

int main() {
  int h,w;
  string s;
  cin >> h >> w;
  for(int i= 0;i<h;i++){
    cin >> s;
    for(int j =0;j<w;j++){
      lc[i][j] = s[j];
    }
  }
  
  int c = 0;
  int mx = 0;
  for(int i= 0;i<h;i++){
    for(int j =0;j<w;j++){
      if(lc[i][j] == '.'){
        if(i> 0 && lc[i-1][j] != '#'){
          co[i][j][0] = co[i-1][j][0];
        }else{
          c = 0;
          for(int k =i;k < h;k++){
            c++;
            if(lc[k+1][j] != '.'){break;}
          }
          co[i][j][0] = c;
        }
        
        if(j> 0 && lc[i][j-1] != '#'){
          co[i][j][1] = co[i][j-1][1];
        }else{
          c = 0;
          for(int k =j;k < w;k++){
            c++;
            if(lc[i][k+1] != '.'){break;}
          }
          co[i][j][1] = c;
        }
      }
      mx = max(co[i][j][0] + co[i][j][1]-1,mx);
      //cout << i << " " << j << " " << co[i][j][0] + co[i][j][1] -1<< endl;
    }
  }
  cout << mx; 
}
