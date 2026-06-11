#include <iostream>
using namespace std;
int main(){
int H,W;
while(1){
    cin>>H>>W;
    if(H==0&&W==0){
        break;
    }
    for(int n=0;n<H;n++){
        for(int i=0;i<W;i++){
            if(i%2==0&&n%2==0){
                cout<<"#";
            }
            else if(i%2==1&&n%2==1){
                cout<<"#";
            }
            else{
                cout<<".";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
return 0;
}

