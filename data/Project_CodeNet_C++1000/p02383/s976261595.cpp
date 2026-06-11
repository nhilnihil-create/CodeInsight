#include <iostream>

using namespace std;

class Dice{
public:
    int mFaces[6];
    void roll_n(){
        int tmp = mFaces[0];
        mFaces[0] = mFaces[1];
        mFaces[1] = mFaces[5];
        mFaces[5] = mFaces[4];
        mFaces[4] = tmp;
    }
    void roll_e(){
        int tmp = mFaces[0];
        mFaces[0] = mFaces[3];
        mFaces[3] = mFaces[5];
        mFaces[5] = mFaces[2];
        mFaces[2] = tmp;
    }
    void roll_s(){
        for(int i = 0; i < 3; ++i){
            roll_n();
        }
    }
    void roll_w(){
        for(int i = 0; i < 3; ++i){
            roll_e();
        }
    }
    void printTop(){
        cout << mFaces[0] << endl;
    }
};

int main()
{
    Dice dice;

    for(int i = 0; i < 6; ++i){
        cin >> dice.mFaces[i];
    }

    char ord;
    while(cin >> ord){
        switch(ord){
            case 'N':
                dice.roll_n();
                break;
            case 'E':
                dice.roll_e();
                break;
            case 'S':
                dice.roll_s();
                break;
            case 'W':
                dice.roll_w();
                break;
        }
    }

    dice.printTop();
}