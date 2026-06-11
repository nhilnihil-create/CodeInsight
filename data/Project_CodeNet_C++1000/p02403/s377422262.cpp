#include <iostream>
using namespace std;

int main(){
    int h,w,i;
    string ans="",temp="";
    while(1){
      cin>>h>>w;
      if (h==0&&w==0)break;
      else{
        for (i=0;i<w;i++)temp+="#";
        temp+="\n";
        for (i=0;i<h;i++)ans+=temp;
        cout<<ans<<endl;
        ans="";temp="";
      }
    }
    return 0;
}


