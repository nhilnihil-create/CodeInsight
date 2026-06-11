#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int64_t ans=0;
  map<pair<char,char>,int> m;
  string s,temp;
  pair<char,char> p;
  for(int i=1;i<=N;i++){
    if(i%10==0){
      continue;
    }
    s=to_string(i);
    p=make_pair(s.front(),s.back());
    if(m.count(p)){
      continue;
    }else{
      m[p]=1;
    }
    queue<string> que;
    que.push(s);
    while(!que.empty()){
      s=que.front();
      que.pop();
      if(s.size()==1){
        temp=s+s.back();
        if(stoi(temp)>N){
          break;
        }
        que.push(temp);
        m.at(p)++;
      }else{
        bool flag=true;
        for(char c='0';c<='9';c++){
          temp=s.substr(0,s.size()-1)+c+s.back();
          if(stoi(temp)>N){
            flag=false;
            break;
          }
          que.push(temp);
          m.at(p)++;
        }
        if(!flag){
          break;
        }
      }
    }
  }
  char f,b;
  for(auto & x:m){
    tie(f,b)=x.first;
    p=make_pair(b,f);
    if(m.count(p)){
      ans+=x.second*m.at(p);
    }
  }
  cout << ans << endl;
  return 0;
}
