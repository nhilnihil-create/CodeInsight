#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
double EPS=1e-10;
double EQ(double a,double b){
    return abs(a-b)<EPS;
}
void fast_stream(){
  std::ios_base::sync_with_stdio(0);
}
template<class T>
string IntToString(T num){
  string res;stringstream ss;ss<<num;
  return ss.str();
}
ll StringToInt(string &str){
  ll res=0;
  for(int i=0;i<(int)str.size();i++)
    res=(res*10+str[i]-'0');
  return res;
}

set<string> st;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    st.insert(s);
  }
  int m;
  cin>>m;
  bool op=false;
  for(int i=0;i<m;i++){
    string s;
    cin>>s;
    if(st.count(s)>0){
      if(!op)cout<<"Opened by ";
      else cout<<"Closed by ";
      op^=1;
    }
    else
      cout<<"Unknown ";
    cout<<s<<endl;
  }
  return 0;
}