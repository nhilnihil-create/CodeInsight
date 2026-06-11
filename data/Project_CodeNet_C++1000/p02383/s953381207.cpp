#include <iostream>
#include <string>
using namespace std;

class Dice {
public:
    int label[6];

    Dice(int* nums) {
        for (int i = 0; i < 6; i++) label[i] = nums[i];
    }

    void printTop() {
        cout << label[0] << endl;
    }

    void roll(char direction) {
        int new_label[6];
        switch (direction) {
            case 'N':
                new_label[0] = label[1];
                new_label[1] = label[5];
                new_label[2] = label[2];
                new_label[3] = label[3];
                new_label[4] = label[0];
                new_label[5] = label[4];
                break;
            
            case 'S':
                new_label[0] = label[4];
                new_label[1] = label[0];
                new_label[2] = label[2];
                new_label[3] = label[3];
                new_label[4] = label[5];
                new_label[5] = label[1];
                break;
            
            case 'E':
                new_label[0] = label[3];
                new_label[1] = label[1];
                new_label[2] = label[0];
                new_label[3] = label[5];
                new_label[4] = label[4];
                new_label[5] = label[2];
                break;
            
            case 'W':
                new_label[0] = label[2];
                new_label[1] = label[1];
                new_label[2] = label[5];
                new_label[3] = label[0];
                new_label[4] = label[4];
                new_label[5] = label[3];
                break;

            default:
                new_label[0] = label[0];
                new_label[1] = label[1];
                new_label[2] = label[2];
                new_label[3] = label[3];
                new_label[4] = label[4];
                new_label[5] = label[5];
        }

        for (int i= 0; i < 6; i++) label[i] = new_label[i];
    }
};

int main(void) {
    int nums[6];
    for (int i = 0; i < 6; i++) cin >> nums[i];
    Dice dice(nums);

    string commands;
    cin >> commands;
    for (int i = 0; i < commands.size(); i++) dice.roll(commands[i]);
    dice.printTop();

    return 0;
}