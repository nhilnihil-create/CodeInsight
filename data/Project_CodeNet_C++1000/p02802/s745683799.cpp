#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool> ones(n);
  vector<int> wa(n,0);
  int wacnt=0;
  int accnt=0;
  rep(i,m){
    int num;
    string str;
    cin >> num >> str;
    num--;
    if(ones[num])continue;
    if(str=="AC"){
      ones[num]=true;
      accnt++;
      wacnt +=wa[num];
    }
    else if (str=="WA")wa[num]++;
  }
  printf("%d %d\n",accnt,wacnt);
  return 0;
}
