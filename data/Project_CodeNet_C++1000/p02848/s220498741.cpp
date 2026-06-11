#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	string s;
  
  cin>>n>>s;
  
  string ans;
  
  for(int i=0;i<s.size();i++){
  	int x=s[i]-'A';//s.at(i)のほうがいいのかなあ
    ans.push_back('A'+(x+n)%26);
  }
  
  cout<<ans<<endl;
}