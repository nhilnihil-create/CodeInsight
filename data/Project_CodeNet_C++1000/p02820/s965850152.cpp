#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  int r,ss,p;cin>>r>>ss>>p;
  int ans=0;
  string s;cin>>s;
  map<int,string>robo;
  for(int i=1;i<=n;i++){
    if(robo.count(i%k))robo.at(i%k).push_back(s.at(i-1));
    else robo[i%k]=s.at(i-1);
  }
  for(auto robot:robo){
    int size=robot.second.size();
    int tmp=0;
    for(int i=0;i<size;i++){
      if(i>0&&robot.second.at(i-1)==robot.second.at(i)){
        tmp++;
      }
      else tmp=0;
      if(robot.second.at(i)=='r'){
        if((i==0||robot.second.at(i-1)!=robot.second.at(i))||tmp%2==0){
          ans+=p;
        }
      }
      if(robot.second.at(i)=='s'){
        if((i==0||robot.second.at(i-1)!=robot.second.at(i))||tmp%2==0){
          ans+=r;
        }
      }
      if(robot.second.at(i)=='p'){
        if((i==0||robot.second.at(i-1)!=robot.second.at(i))||tmp%2==0){
          ans+=ss;
        }
      }
    }
  }
  cout <<ans<<endl;
}