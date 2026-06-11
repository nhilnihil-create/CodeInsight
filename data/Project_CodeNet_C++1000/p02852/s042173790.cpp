#include<iostream>
#include<string>
#include<vector>

class C{
  int N,M;
  std::string S;
  
public:
  void solve();
};

void C::solve(){
  std::cin>>N>>M>>S;
  std::vector<int> ans;
  int cur=N;
  while(cur>0){
    if(cur-M<=0){
      ans.push_back(cur);
      break;
    }
    bool flag=1;
    for(int i=M;i>0;i--){
      if(S[cur-i]=='0'){
        ans.push_back(i);
        cur-=i;
        flag=0;
        break;
      }
    }
    if(flag){
      std::cout<<"-1\n";
      return;
    }
  }
  for(int i=ans.size()-1;i>=0;i--)
    std::cout<<ans[i]<<" ";
  std::cout<<"\n";
}

int main(){
  C c;
  c.solve();
  return 0;
}
  