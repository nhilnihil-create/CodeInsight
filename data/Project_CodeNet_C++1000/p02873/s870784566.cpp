#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    string s;
  cin >> s;
  int n=(int)s.size()+1;
  vector <unsigned long long> t;
  vector <unsigned long long> l;
  int tmp=1;
  
  rep(i,n-2){
    if(s.at(i)==s.at(i+1)){
      tmp++;
    }else{
      
      t.push_back(tmp);
      tmp=1;
      //cout << t.at((int)t.size()-1) << endl;
      if(s.at(i)=='<' && s.at(i+1)=='>'){
        l.push_back((int)t.size());
        //cout << l.at((int)l.size()-1) << endl;
      }
    }
  }
  
  t.push_back(tmp);
  //cout << t.at((int)t.size()-1) << endl;
  
  unsigned long long ans = 0;
  
  rep(i,(int)t.size()){
    ans+=(t.at(i)*(t.at(i)+1)/2);
    //cout << ans << endl;
  }
  
  
  rep(i,(int)l.size()){
    //cout << t.at(l.at(i)-1) << endl;
    //cout << t.at(l.at(i)) << endl;
    ans-=min(t.at(l.at(i)-1),t.at(l.at(i)));
  }
  
  cout << ans << endl;
 
}

