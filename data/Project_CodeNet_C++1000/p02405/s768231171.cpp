#include<iostream>
using namespace std;
int main(){
    while(1){
        int h, w, k = 1;
        char mark[] = {'#', '.'};
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        for(int i = 0; i < h; i++){
            k = 1 - k;
            int l = k;
            for(int j = 0; j < w; j++){
                cout << mark[l];
                l = 1 - l;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

