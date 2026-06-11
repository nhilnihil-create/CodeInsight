#include <iostream>
using namespace std;
int main(void){
    int h,w;
    while(cin>>h>>w,h!=0||w!=0){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if((j%2+i%2)%2)cout<<".";
                else cout<<"#";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
