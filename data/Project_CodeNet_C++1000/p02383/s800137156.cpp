#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Dice{

public:
    Dice(){
        num = new int[7];
    }

    ~Dice(){
        delete[] num;
    }

    int setLabel(int i, int label){
        num[i] = label;
    }

    int top(){
        return num[1];
    }

    int roll(char dir){
        int tmp[7];
        memcpy(tmp, num, 7*sizeof(int));
        if(dir == 'W'){
            num[1] = tmp[3];
            num[3] = tmp[6];
            num[6] = tmp[4];
            num[4] = tmp[1];
        }
        else if (dir == 'E')
        {
            num[1] = tmp[4];
            num[3] = tmp[1];
            num[6] = tmp[3];
            num[4] = tmp[6];
        }
        else if(dir == 'S')
        {
            num[1] = tmp[5];
            num[2] = tmp[1];
            num[6] = tmp[2];
            num[5] = tmp[6];
        }
        else if(dir == 'N')
        {
            num[1] = tmp[2];
            num[2] = tmp[6];
            num[6] = tmp[5];
            num[5] = tmp[1];
        }
    }

private:
    int *num;

};

int main(){
    Dice dice;
    
    for(int i=0; i<6;i++){
        int label;
        cin >> label;
        dice.setLabel(i+1, label);
    }

    char dir;
    cin >> dir;
    do{
        dice.roll(dir);
        // cout << dice.top() << endl;
    } while((dir = getchar())!= '\n');

    cout << dice.top() << endl;
}
