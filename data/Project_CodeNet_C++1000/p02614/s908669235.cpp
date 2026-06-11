#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int h,w,k;
  int count_bk=0,ans=0;
  cin >> h >> w >> k;
  vector<vector<char>>c(h+1,vector<char>(w+1));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> c.at(i).at(j);
      if(c.at(i).at(j) == '#'){
        count_bk++;
      }
    }
  }
  for(int i=0;i<(1<<h);i++){
    for(int j=0;j<(1<<w);j++){
      int temp=count_bk;
      for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
          if(i&(1<<x) || j&(1<<y)){
            if(c.at(x).at(y)=='#'){
              temp--;
            }//if
          }//if
        }//for y
      }//for x
      if(temp == k){
        ans++;
      }
    }//for j
  }//for i
  cout << ans << endl;
}