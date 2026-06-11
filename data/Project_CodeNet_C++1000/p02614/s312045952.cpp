#include <bits/stdc++.h>
using namespace std;




int main() {
  int h,w,K;
  cin>>h>>w>>K;
  
  vector<string> c(h, string(w,'.'));
  for(int i=0; i<h; i++){
    string si; cin>>si;
    c[i]=si;
  }
  
  
  // 行,列の選び方パターン
  vector<vector<bool> > hchoice(pow(2,h),vector<bool>(h,0));
  vector<vector<bool> > wchoice(pow(2,w),vector<bool>(w,0));
  for(int i=0; i<pow(2,h); i++){
    int temp=i;
    for(int j=0; j<h; j++){
      hchoice[i][j]=temp%2; temp/=2;
    }
  }
  for(int i=0; i<pow(2,w); i++){
    int temp=i;
    for(int j=0; j<w; j++){
      wchoice[i][j]=temp%2; temp/=2;
    }
  }
  
  
  int res=0;
  for(int i=0; i<hchoice.size(); i++){
    for(int j=0; j<wchoice.size(); j++){
      int cnti=0;
      for(int p=0; p<h; p++){
        if(!hchoice[i][p]){
          for(int q=0; q<w; q++){
            if(!wchoice[j][q]){
              cnti+=(c[p][q]=='#');
            }
          }
        }
      }
      res+=(cnti==K);
    }
  }
  
  cout<<res<<endl;
  
}
