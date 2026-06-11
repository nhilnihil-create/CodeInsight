#include <iostream>

using namespace std;

int main()
{
    int dice[6];
    for(int i=0; i<6; ++i){
        cin >> dice[i];
    }

    string s;
    cin >> s;
    int tmp;
    for(const auto& c: s){
        switch(c){
            case('S'):
                tmp = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[0];
                dice[0] = dice[4];
                dice[4] = tmp;
                break;
            case('N'):
                tmp = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[0];
                dice[0] = dice[1];
                dice[1] = tmp;
                break;
            case('E'):
                tmp = dice[5];
                dice[5] = dice[2];
                dice[2] = dice[0];
                dice[0] = dice[3];
                dice[3] = tmp;
                break;
            case('W'):
                tmp = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[0];
                dice[0] = dice[2];
                dice[2] = tmp;
                break;
        }


    }

    cout << dice[0] << endl;

    return 0;
}
