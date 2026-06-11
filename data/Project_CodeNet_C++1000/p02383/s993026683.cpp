#include <iostream>
#include <string>

using namespace std;

class Dice {
    public:
        int value[6];
        Dice(int* num);
        void rotate(char direction);
};

//constructor
Dice::Dice(int *num) {
    for (int i = 0; i < 6; i++)
    {
        Dice::value[i] = num[i];
    }
};

void Dice::rotate(char direction) {
    int tmp;
    switch(direction) {
        case 'N':
            tmp = Dice::value[0];
            Dice::value[0] = Dice::value[1];
            Dice::value[1] = Dice::value[5];
            Dice::value[5] = Dice::value[4];
            Dice::value[4] = tmp;
            break;

        case 'S':
            tmp = Dice::value[0];
            Dice::value[0] = Dice::value[4];
            Dice::value[4] = Dice::value[5];
            Dice::value[5] = Dice::value[1];
            Dice::value[1] = tmp;
            break;

        case 'W':
            tmp = Dice::value[0];
            Dice::value[0] = Dice::value[2];
            Dice::value[2] = Dice::value[5];
            Dice::value[5] = Dice::value[3];
            Dice::value[3] = tmp;
            break;

        case 'E':
            tmp = Dice::value[0];
            Dice::value[0] = Dice::value[3];
            Dice::value[3] = Dice::value[5];
            Dice::value[5] = Dice::value[2];
            Dice::value[2] = tmp;
            break;

        default:
        ;
    }
}

int main() {
    int num[6] = {};
    string s;
    for(int i = 0; i < 6; i++) {
        cin >> num[i];
    }
    Dice dice1 = Dice(num);
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        dice1.rotate(s[i]);
    }
    cout << dice1.value[0] << endl;
    return 0;
}
