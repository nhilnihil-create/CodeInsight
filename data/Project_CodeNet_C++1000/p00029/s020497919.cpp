#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstdio>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define it ::iterator
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double ESP=1e-10;
using namespace std;
int main(){
  string s;
  vector<string> line;
  vector<int> cnt;
  getline(cin,s);
  string word = "";
  string longest = "";
  
  rep(i,s.size()){
    if(s[i] == ' '){
      if(longest.size() < word.size()){
	longest = word;
      }
      bool find = false;
      
      rep(j,line.size()){
	if(line[j] == word){
	  cnt[j] ++;
	  find = true;
	  word = "";
	}
      }
      
      if(find)continue;
      line.pb(word);
      word = "";
    }else{
      word += s[i];
      cnt.pb(1);
    }
  }
  
  int ma = 0;
  string res = "";
  
  rep(i,line.size()){
    if(ma < cnt[i]){
      ma = cnt[i];
      res = line[i];
    }
  }
  
  cout<<res<<" "<<longest<<endl;

}