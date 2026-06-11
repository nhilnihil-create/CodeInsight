#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>

#define INF 999999999
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=(n);i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define MOD(x) (x%(mod))
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

/*---------------------------------------------------*/

string a;
int L;
map<string,int>data;

string add_zero(string s){
  while(s.size()!=L){
    s="0"+s;
    //cout<<"s: "<<s<<endl;
  }
  return s;
}


int str_to_int(string s){
  //cout<<"s"<<s<<endl;
  int n=0,ten=1;
  char c;
  ten=pow(10,L-1);
  rep(i,s.size()){
    c=s[i];
    n+=int(c-'0')*ten;
    ten/=10;
  }
  return n;
}

string change_str(string s){
  s=add_zero(s);
  sort(all(s));
  int mini=str_to_int(s);
  reverse(all(s));
  int maxi=str_to_int(s);
  //cout<<mini<<" "<<maxi<<endl;
  maxi-=mini;
  string str;
  str=to_string(maxi);
  str=add_zero(str);
  //cout<<"str: "<<str<<endl;
  return str;
}

void solve(){
  data.clear();
  int cnt=1;
  a=add_zero(a);
  data.insert(make_pair(a,0));
  string str=change_str(a);
  while(1){
  	//cout<<str<<endl;
    if(data.find(str)!=data.end())break;
    data.insert(make_pair(str,cnt));
    str=change_str(str);
    cnt++;
  }
  cout<<data[str]<<" "<<str_to_int(str)<<" "<<cnt-data[str]<<endl;
}


int main(){
  while(cin>>a>>L){
    if(a=="0"&&L==0)break;
    solve();
  }
  return 0;
}