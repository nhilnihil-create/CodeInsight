#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int a;
    cin >> a;
    mp[a] ++;
  }
  //case1
  if(mp.size()==1 && mp[0]>0){
    cout << "Yes" << endl;
    return 0;
  }//mp.size()
  if(n%3 != 0){
    cout << "No" << endl;
    return 0;
  }
  //case2
  if(mp.size() == 2){
    int key = 0;
    bool suc1 = 0;
    bool suc2 = 0;
    for(auto p : mp){
      if(key==0 && p.second==n/3){
        suc1 = 1;
      }
      if(key==1 && p.second==2*n/3){
        suc2 = 1;
      }
      key ++;
    }//p
    if(suc1 && suc2){
      cout << "Yes" << endl;
      return 0;
    }
  }//mp.size()
  //case3
  if(mp.size() == 3){
    for(auto p : mp){
      if(p.second != n/3){
        cout << "No" << endl;
        return 0;
      }//p.second
    }//p
    int a,b,c;
    int key = 0;
    for(auto p : mp){
      if(key == 0) a = p.first;
      if(key == 1) b = p.first;
      if(key == 2) c = p.first;
      key ++;
    }//p
    if((a^b) == c){
      cout << "Yes" << endl;
      return 0;
    }//a^b
  }//mp.size()
  cout << "No" << endl;
}