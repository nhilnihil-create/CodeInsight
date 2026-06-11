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
    }
    int top(){
        return s[0];
    }
};

int main(){
    struct Dice Dice;
    for(int i = 0;i < 6;i++)
        cin >> Dice.s[i];
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++)
        Dice.roll(s[i]);
    cout << Dice.top() << endl;

    return 0;
}
