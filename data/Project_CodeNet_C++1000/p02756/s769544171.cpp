#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  string s;
  int q;
  cin >> s >> q;
  int front =1;
  int back=2;
  string sfront="";
  string sback="";
  rep(i,q){
    int t;
    cin >> t;
    if(t==1){
      front=3-front;
      back=3-back;
    }
    else if(t==2){
        int f;
        cin >> f;
        char c;
        cin >> c;
        if(f==1){
            if(front==1)sfront+=c;
            else if(front==2)sback+=c;
        }
        else if(f==2){
            if(back==2)sback+=c;
            else if(back==1)sfront+=c;
        }
    }
  }
  if(front==1){
      reverse(sfront.begin(),sfront.end());
      cout << sfront << s << sback << endl;
  }
  else if(front==2){
    reverse(sback.begin(),sback.end());
    reverse(s.begin(),s.end());
    cout << sback << s << sfront << endl;

  }
}