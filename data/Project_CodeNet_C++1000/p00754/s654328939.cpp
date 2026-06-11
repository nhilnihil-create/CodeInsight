#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#define INF 2000000000
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define ll long long
#define PL pair<long long, long long>
#define PR pair<int,int>
#define mk make_pair
#define en endl;
#define WHITE 0
#define BLACK 2
#define GRAY 1
#define RE return 0;

//#define int ll

// the balance of the world

signed main(){
  while(1){
    stack<char> s;
    string str;
    getline(cin, str);
    if(str==".") break;
    
    bool ans=1;
    for(int i=0; i<str.size(); i++){
      if(str[i]=='('||str[i]=='['){
        s.push(str[i]);
      }else if(str[i]==')'||str[i]==']'){
        if(s.empty()) ans=0;
        else if(str[i]==']'&&s.top()=='['){
          s.pop();
        }else if(str[i]==')'&&s.top()=='('){
          s.pop();
        }else{
          ans=0;
        }
      }else if(str[i]=='.'){
        if(ans&&s.empty()) cout<<"yes"<<en
        else cout<<"no"<<en
          break;
      }
    }
  }
  RE
}
