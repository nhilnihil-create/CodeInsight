#include<bits/stdc++.h>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>
 
using namespace std;

int main(){
  int a,b,c,d;
  bool ans;
  cin >> a >> b >> c >> d;
  while(true){
    c -= b;
    if(c <= 0){
      ans = true;
      break;
    }
    a -= d;
    if(a <= 0){
      ans = false;
      break;
    }
  }
  ans ? cout << "Yes" << endl : cout << "No" << endl;
}
