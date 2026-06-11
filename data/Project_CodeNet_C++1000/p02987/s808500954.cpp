#include "iostream"
#include "string"
using namespace std;


int main(){
  string s;
  cin>>s;
  int d=0;
  for(int i=0;i<4;i++){
    if(s[i]==s[0]){
      d++;

    }
  }
  if((d==3)||((d==1)&&(s[1]==s[2]==s[3]))){
    cout<<"Yes"<<endl;
  }
  else if((d==2)){
    string h[2];
    int y=0;
    for(int i=1;i<4;i++){

      if(s[0]!=s[i]){
        h[y]=s[i];
        y++;

      }
    }
    if(h[0]==h[1]){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
  else{
    cout<<"No"<<endl;
  }

}
