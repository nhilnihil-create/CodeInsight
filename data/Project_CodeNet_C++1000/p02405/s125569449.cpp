#include <iostream>
using namespace std;

int main(){
    int h,w,i;
    bool b=true;
    string ans="",temp1="",temp2="";
    while(1){
      cin>>h>>w;
      if (h==0&&w==0)break;
      else{
        for (i=0;i<w;i++){
          if (b)temp1+="#";
          else temp1+=".";
          b=!b;
        }
        b=false;
        for (i=0;i<w;i++){
          if (b)temp2+="#";
          else temp2+=".";
          b=!b;
        }
        b=true;
        for (i=0;i<h;i++){
          if (b)ans+=temp1+"\n";
          else ans+=temp2+"\n";
          b=!b;
        }
        cout << ans << endl;
        ans="";temp1="";temp2="";b=true;

    }}
    return 0;
}


