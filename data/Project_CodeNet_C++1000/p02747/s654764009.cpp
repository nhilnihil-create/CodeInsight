#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  string s;
  cin>>s;
int judge=0;
  for(int i=0;i<s.size()-1;i++){
    if(s.size()>1&&s[i]=='h'&&s[i+1]=='i'){
judge++;
    }
  }
  if(judge==(s.size()/2)&&s.size()%2==0){
cout<<"Yes"<<endl;
  }
  else{
cout<<"No"<<endl;
  }

return 0;
}