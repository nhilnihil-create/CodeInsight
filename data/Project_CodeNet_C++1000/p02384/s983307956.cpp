#include <iostream>
#include <string>
using namespace std;

struct Dice{
    int s[6];
    void roll(char ope){
        int b;
        if(ope == 'E'){
            swap(s[0],s[2]);
            swap(s[0],s[5]);
            swap(s[0],s[3]);
        }
        if(ope == 'W'){
            swap(s[0],s[3]);
            swap(s[0],s[5]);
            swap(s[0],s[2]);
        }
        if(ope == 'S'){
            swap(s[0],s[1]);
            swap(s[0],s[5]);
            swap(s[0],s[4]);
        }
        if(ope == 'N'){
            swap(s[0],s[4]);
            swap(s[0],s[5]);
            swap(s[0],s[1]);
        }
        if(ope == 'R'){
            swap(s[1],s[2]);
            swap(s[1],s[4]);
            swap(s[1],s[3]);
        }
    }
    int top(){
        return s[0];
    }
    int right(){
        return s[2];
    }
    int left(){
        return s[3];
    }
    int front(){
        return s[1];
    }
};

int main(){
    struct Dice Dice;
    for(int i = 0;i < 6;i++)
        cin >> Dice.s[i];
    int n;
    cin >> n;
    while(n--){
        int a,b;
        cin >> a >> b;
        if(Dice.left() == a)
            Dice.roll('E');
        if(Dice.right() == a)
            Dice.roll('W');
        while(Dice.top() != a)
            Dice.roll('N');
        while(Dice.front() != b)
            Dice.roll('R');
        cout << Dice.right() << endl;
    }

    return 0;
}
