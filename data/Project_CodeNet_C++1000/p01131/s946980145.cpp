#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

int N;
string wa[10]={ "",
		".,!? ",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"};
vector<char> ans;
int main(){
  cin >> N;
  for(int t=0;t<N;t++){
    string s;
    cin >> s;
    int pr = 0;
    int jd = 0;
    ans.clear();
    for(int i=0;i<(int)s.size();i++){
      int id = s[i]-'0';
      if( id == 0 ){
	//	cout << wa[pr][jd] << endl;
	if( pr!=0 ) ans.push_back(wa[pr][jd]);
      } else if( pr != id ){
	jd = 0;
      } else {
	jd = (jd+1)%(int)wa[id].size();
      }
      pr = id;
    }
    for(int i=0;i<(int)ans.size();i++){
      cout << ans[i];
    }
    cout << endl;
  }
}