#include<iostream>
using namespace std;
int main(void){
      int h,w,k;
      while(1){
            cin>>h>>w;
            if(h==0&&w==0)break;
            for(int i=0;i<h;i++){
                  for(int j=0;j<w;j++){
                        k=i+j;
                        if(k%2!=0){
                              cout<<".";
                        }
                        else{
                              cout<<"#";
                        }
                  }
                  cout<<endl;
            }
            cout<<endl;
      }
      return 0;
}
      
