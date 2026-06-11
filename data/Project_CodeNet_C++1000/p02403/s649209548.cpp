#include <iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h;
    int w;
    while(cin>>h>>w){
        if(h == 0 && w == 0)
            break;

        for(int j = 0; j < h; j++){
            for(int i = 0; i < w; i++){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}