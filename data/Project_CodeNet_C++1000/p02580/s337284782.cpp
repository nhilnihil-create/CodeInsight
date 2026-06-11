#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;


int main(){
  int h,w,m;
  cin >> h >> w >> m;
  //vector<pair<int,int>> hw(m);
  map<P,int> mp;
  vector<int> yoko(w,0),tate(h,0);
  int hnum=-1;
  int wnum=-1;
  for(int i=0;i<m;++i){
    int h,w;
    cin >> h >> w;
    h--;
    w--;
    mp[P(h,w)]++;
    tate[h]++;
    yoko[w]++;
  }
  int hid;
  vector<int> hkouho;
  for(int i=0;i<h;++i) hnum=max(hnum,tate[i]);
  for(int i=0;i<w;++i) wnum=max(wnum,yoko[i]);
  for(int i=0;i<h;++i){
    //cout << tate[i] << endl;
    if(hnum==tate[i]){
      hkouho.push_back(i);
    }
  }
  //for(int i=0;i<hkouho.size();++i) cout << hkouho[i] << endl;
  int wid;
  vector<int> wkouho;
  for(int i=0;i<w;++i){
    //cout << yoko[i] << endl;
    if(wnum==yoko[i]) wkouho.push_back(i);
  }
  int ans=hnum+wnum;
  //cout << ans << endl;
  bool ok=false;
  for(int i=0;i<hkouho.size();++i){
    for(int j=0;j<wkouho.size();++j){
      //cout << mp[P(hkouho[i],wkouho[j])] << endl;
      if(ok){
        i=hkouho.size()+1;
        break;
      }else{
        if(mp[P(hkouho[i],wkouho[j])]==0){
          ok=true;
        }
      }
    }
  }
  if(!ok) ans--;
  cout << ans << endl;
  return 0;
}
