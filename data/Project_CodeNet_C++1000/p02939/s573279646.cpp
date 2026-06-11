#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
string s; cin>>s;
int count = 0;
//s += "#";
int flag = 2;
rep(i,s.size()-1){
//cout<<"s[i] =="<< s[i]<<" s[i+1] == "<<s[i+1];
  if(flag == 0){
      flag += 1;
  //  cout<<" "<<1<<endl;
     
  }else if(flag == 1){
      flag = 2;
      count++;
   //      cout<<" "<<1.5<<endl;
  }
      else if(s[i] != s[i+1]){
      count++;
  //    cout<<" "<<2<<endl;
  }else if(s[i] == s[i+1]){
      count++;
      flag = 0;
  //       cout<<" "<<3<<endl;
  }
}
if(flag == 0 && s[s.size()-2] == s[s.size()-1]) count--;


cout<<count+1<<endl;
    return 0;
}
