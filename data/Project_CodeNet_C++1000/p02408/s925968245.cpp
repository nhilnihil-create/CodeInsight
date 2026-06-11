#include <iostream>

using namespace std;

int cards[4][13];
int main(){
    int n;
    cin >> n;
    char c;
    int cn;
    for (int i = 0; i < n; i++){
        cin >> c >> cn;
        switch (c){
            case 'S':
                cards[0][cn-1] = 1;
                break;
            case 'H':
                cards[1][cn-1] = 1;
                break;
            case 'C':
                cards[2][cn-1] = 1;
                break;
            case 'D':
                cards[3][cn-1] = 1;
                break;
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            if(!cards[i][j]) {
                char s;
                switch(i){
                    case 0: s = 'S'; break;
                    case 1: s = 'H'; break;
                    case 2: s = 'C'; break;
                    case 3: s = 'D'; break;
                }
                cout << s << " " << j+1 << endl;
            }
        }
    }
}