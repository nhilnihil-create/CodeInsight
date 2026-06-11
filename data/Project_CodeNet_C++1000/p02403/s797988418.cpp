#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int x,y;
    for(;;){
        cin>>x>>y;
        if(x==0&&y==0){
            break;
        }
        for(int i=1;i<=x;i++){
            for(int o=1;o<=y;o++){
                cout<<'#';
            }
            cout<<endl;
        }
        cout<<endl;
        }
    return 0;
}

