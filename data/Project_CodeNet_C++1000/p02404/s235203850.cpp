#include<iostream>
using namespace std;

inline void draw(char c, int n){
	for(int i = 0; i < n; i++) cout << c;
}

int main()
{
    int H, W, i;
	while(1){
        cin >> H >> W;
        if(H + W < 1) break;
        draw('#', W); cout << endl;
        for(i = 1; i < H - 1; i++){
            cout << '#'; draw('.', W - 2); cout << '#' << endl;
        }
        draw('#', W); cout << endl;
        cout << endl;
    }

    return 0;
}