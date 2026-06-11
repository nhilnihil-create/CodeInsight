#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class Dice
{

  public:
    Dice()
    {
        num = new int[7];
        // rl[1][0] = 2;
        // rl[1][1] = 3;
        // rl[1][2] = 5;
        // rl[1][3] = 4;

        // rl[2][0] = 3;
        // rl[2][1] = 1;
        // rl[2][2] = 4;
        // rl[2][3] = 6;

        // rl[3][0] = 2;
        // rl[3][1] = 6;
        // rl[3][2] = 5;
        // rl[3][3] = 1;
    }

    ~Dice()
    {
        delete[] num;
    }

    int setLabel(int i, int label)
    {
        num[i] = label;
    }

    int rightOn(int top, int front){
        top = idx(top);
        front = idx(front);

        int dir = 1;
        if(top > 3){
            dir = -1;
            top = 7 - top;
        }

        for(int i=0;i<4;i++){
            if(rl[top][i] == front){
                return num[rl[top][(4 + i + dir)%4]];
            }
        }
        return -1;
    }

  public:
    static int rl[4][4];

  private:
    int *num;

  private:
    int idx(int label){
        for(int i = 0; i< 6;i++){
            if(label == num[i+1])
                return i+1;
        }
        return -1;
    }

};
int Dice::rl[4][4]={{0}, {2,3,5,4}, {3,1,4,6},{2,6,5,1}};

int main()
{
    Dice dice;

    for (int i = 0; i < 6; i++)
    {
        int label;
        cin >> label;
        dice.setLabel(i + 1, label);
    }

    int n;
    cin >> n;
    while(n--){
        int top, front;
        cin >> top >> front;
        cout << dice.rightOn(top, front) << endl;
    }
}
