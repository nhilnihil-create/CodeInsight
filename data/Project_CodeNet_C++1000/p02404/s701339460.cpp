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

        string top_and_bottom = string(w, '#');

        cout << top_and_bottom << endl;
        for(int j = 1; j < h - 1; j++){
            cout << "#";
            for(int i = 1; i < w - 1; i++){
                cout << ".";
            }
            cout << "#" << endl;
        }
        cout << top_and_bottom << endl;
        cout << endl;
    }

    return 0;
}