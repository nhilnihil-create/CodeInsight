#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
const long long MOD=1e09+7;



#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()




int main(){
  
  int h,w;
  cin>>h>>w;
  
  vector<string> data(h);
  rep(i,h){
    string tmp;
    cin>>tmp;
    data.at(i)=tmp;
  }
  
 
  vector<vi> rows(h,vi(0));
  vector<vi> cols(w,vi(0));
  
  rep(i,h){
    rep(j,w){
      if (data.at(i).at(j)=='#'){
        rows.at(i).push_back(j);
      }
    }
  }
  rep(j,w){
    rep(i,h){
      if (data.at(i).at(j)=='#'){
        cols.at(j).push_back(i);
      }
    }
  }
  

  
  int answer=0;
  
  rep(i,h){
    rep(j,w){
      if (data.at(i).at(j)='.'){
        int left,right,up,down;
        int tmplr=distance(rows.at(i).begin(),lower_bound(ALL(rows.at(i)),j));
        if (tmplr==0){
          left=0;
        }
        else {
          left=rows.at(i).at(tmplr-1)+1;
        }
        if (tmplr==int (rows.at(i).size())){
          right=w-1;
        }
        else {
          right=rows.at(i).at(tmplr)-1;
        }
        
        int tmpud=distance(cols.at(j).begin(),lower_bound(ALL(cols.at(j)),i));
        if (tmpud==0){
          up=0;
        }
        else {
          up=cols.at(j).at(tmpud-1)+1;
        }
        if (tmpud==int(cols.at(j).size())){
          down=h-1;
        }
        else {
          down=cols.at(j).at(tmpud)-1;
        }
        
        answer=max(answer,(right-left)+(down-up)+1);
      }
    }
  }
  
  cout<<answer<<endl;
  


}








