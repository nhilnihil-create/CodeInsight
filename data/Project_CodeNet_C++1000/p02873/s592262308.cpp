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
int S[s.size()+1],L[s.size()+1];
ll cntS=0,cntL=0;
S[0] = 0;
for(int i = 1; i < s.size()+1; i++){
    if(s[i-1] == '<') {
        cntS++;
        S[i] = cntS;
    }else
    {
        cntS = 0;
        S[i] = 0;
    }//左側にある＜の数を数える
}
L[s.size()] = 0;
for(int i = s.size()-1; i >= 0; i--){
    if(s[i] == '>'){
        cntL++;
        L[i] = cntL;
    }else
    {
        cntL = 0;
        L[i] = 0;
    }    
}//右側にある＞の数を数える
ll ans = 0;
rep(i,s.size()+1){
  //  cout<<"S[i] =="<<S[i]<<" L[i]=="<<L[i]<<endl;
ans += max(S[i],L[i]);
//cout<<ans<<endl;
}//＜と＞の数が大きい方を数える

cout<<ans<<endl;
    return 0;
}
