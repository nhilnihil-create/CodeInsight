#include <iostream>
using namespace std;
int main(void){
    int a,b;
    while(1){
        int k=0;
        cin>>a>>b;
        if(a==0&&b==0)break;
    for(int i = 1;i<=a;i++){
        for(int j = i+1;j<=a;j++){
            for(int l = j+1;l<=a;l++){
                if(b==i+j+l){
                    k++;
                }
            }
        }
    }
    cout<<k<<endl;
  }
}
