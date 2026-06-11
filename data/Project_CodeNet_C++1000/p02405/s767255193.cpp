#include <iostream>
using namespace std;
int main(){
    int h,w;
    while(1){
        cin >> h >> w;
        if(h == 0 && w ==0) break;
        else{
            for(int y=1;y<=h;y++){
                for(int x=1;x<=w;x++){
                    if((x+y)%2==0) cout << "#";
                    else cout << ".";
                }
                cout <<endl;
            }
            cout <<endl;
        }
    }
    return 0;
}