#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> sett = {
  {'.', ',', '!', '?', ' '},
  {'a', 'b', 'c'},
  {'d', 'e', 'f'},
  {'g', 'h', 'i'},
  {'j', 'k', 'l'},
  {'m', 'n', 'o'},
  {'p', 'q', 'r', 's'},
  {'t', 'u', 'v'},
  {'w', 'x', 'y', 'z'}
};


int main(){
  int N; cin >> N;
  vector<string> anss;
  for(int i = 0 ; i < N ; i++){
    string inp; cin >> inp;
    string ans;
    int count = 0;
    int pre = 0;
    for(int j = 0 ; j < inp.size(); j++){
      if(inp[j] == '0'){
        if(count == 0) continue;
        ans.push_back(sett[pre-1][(count-1)%sett[pre-1].size()]);
        count = 0;
      }
      else{
        pre = inp[j] - '0';
        count++;
      }
    }
    anss.push_back(ans);
  }
  for(int i = 0 ; i < N ; i++){
      cout << anss[i] << endl;
  }
}

