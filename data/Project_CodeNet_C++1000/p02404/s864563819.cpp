#include <iostream>
using namespace std;
int main(){
    int H,W;
    int i=0;
    while(1){
        cin>>H>>W;
        if(H==0&&W==0){
            break;
        }
        for(int n=1;n<=H;n++){
            for(int i=1;i<=W;i++){
                if(n==1){
                    cout<<"#";
                }
                 else if(n==H){
                    cout<<"#";
                }
                else{
                    if(i==1){
                        cout<<"#";
                    }
                    else if(i==W){
                        cout<<"#";
                    }
                    else{
                        cout<<".";
                    }
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
