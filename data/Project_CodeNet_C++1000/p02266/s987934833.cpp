#include<bits/stdc++.h>
using namespace std;
int main(){
  stack<int> st;
  stack<int> sti;
  vector<int> ans;
  int co=0;
  char ch;
  int zn=0;
  for(int i=0;;i++){
    cin >> ch;
    if(cin.eof())break;
    if(ch=='\\'){
      st.push(i);
      sti.push(0);
      zn++;
    }
    else if(ch=='/'){
      if(!st.empty()){
	int to;
	while(1){
	  to=st.top();
	  st.pop();
	  if(to>=0)break;
	}
	if(zn!=0){
	  int c=0;
	  while(1){
	    
	    int toi=sti.top();
	    sti.pop();
	    c+=toi;
	    if(toi==0){
	      c+=i-to;
	      sti.push(c);
	      zn--;
	      break;
	    }
	  }
	}
	co+=i-to;
      }
    }
  }
  while(!sti.empty()){
    if(sti.top())
      ans.push_back(sti.top());
    sti.pop();
  }
  cout << co << endl;
  cout << ans.size();
  for(int i=ans.size()-1;i>=0;i--){
    cout << " "<<ans[i];
  }
  cout << endl;
  return 0;
}