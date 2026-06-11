#include <iostream>
using namespace std;

int main(){
    int h,w,i;
    string ans="",temp1="#",temp2="";
    while(1){
      cin>>h>>w;
      if (h==0&&w==0)break;
      else{
        for (i=0;i<w-2;i++)temp1+=".";
        temp1+="#\n";
        for (i=0;i<w;i++)temp2+="#";
        temp2+="\n";
        ans+=temp2;
        for (i=0;i<h-2;i++)ans+=temp1;
        ans+=temp2;
        cout<<ans<<endl;
        ans="";temp1="#";temp2="";
      }
    }
    return 0;
}


