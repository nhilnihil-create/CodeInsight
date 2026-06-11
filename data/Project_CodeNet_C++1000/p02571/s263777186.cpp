#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
#define Yes cout<<"Yes"<<endl; 
#define No cout<<"No"<<endl;
#define YES cout<<"YES"<<endl; 
#define NO cout<<"NO"<<endl;
#define yes cout<<"yes"<<endl; 
#define no cout<<"no"<<endl;

// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
  string s,t;cin>>s>>t;
  int cnt=0;
  rep(i,s.size()-t.size()+1){
      int cnt1 = 0;
      rep(j,t.size()){
          if(s[i+j] == t[j])cnt1++;
      }
      cnt = max(cnt,cnt1);
  }
   cout<<t.size() - cnt<<endl;

    return 0;
}
