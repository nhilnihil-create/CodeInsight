#include<bits/stdc++.h>
using namespace std;

struct water{
  int left,sum;
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  stack<int> st1;
  stack<water> st2;
  int sum=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='\\'){
      st1.push(i);
    }else if(s[i]=='/'){
      if(st1.empty()==true){
        continue;
      }
      int temp=i-st1.top();
      sum+=temp;
      while(!st2.empty()&&st2.top().left>st1.top()){
        temp+=st2.top().sum;
        st2.pop();
      }
      water a;
      a.left=st1.top();
      a.sum=temp;
      st2.push(a);
      st1.pop();
    }
  }
  cout<<sum<<endl<<st2.size()<<flush;
  stack<int> ans;
  while(!st2.empty()){
    ans.push(st2.top().sum);
    st2.pop();
  }
  while(!ans.empty()){
    cout<<" "<<ans.top()<<flush;
    ans.pop();
  }
  cout<<endl;
  return 0;
}
