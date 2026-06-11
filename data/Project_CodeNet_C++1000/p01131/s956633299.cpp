#include <bits/stdc++.h>
using namespace std;

string s,ans;
int n,num,now;
int csize[10]={0,5,3,3,3,3,3,4,3,4};
char btn[10][5]={
  {'-','-','-','-','-'},
  {'.',',','!','?',' '},
  {'a','b','c','-','-'},
  {'d','e','f','-','-'},
  {'g','h','i','-','-'},
  {'j','k','l','-','-'},
  {'m','n','o','-','-'},
  {'p','q','r','s','-'},
  {'t','u','v','-','-'},
  {'w','x','y','z','-'}
};

int main(){
  int i,a,j;
  cin >> n;
  for(a=0;a<n;a++){
    ans="";
    cin >> s;
    for(i=0;i<s.size();i++){
      now = s[i]-'0';
      num=0;
      if(now==0)continue;
      while(s[++i]==now+'0')num++;
      ans+=btn[now][num%csize[now]];
    }
    cout << ans << endl;
  }
  return 0;
}

