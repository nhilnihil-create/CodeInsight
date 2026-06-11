#include <iostream>

struct TDice
{
    int Top;
    int Front;
    int Right;
    int Back;
    int Left;
    int Bottom;
};
TDice MakeDice(std::istream& in)
{
    TDice Dice;
    in >> Dice.Top
       >> Dice.Front
       >> Dice.Right
       >> Dice.Left
       >> Dice.Back
       >> Dice.Bottom;
    return Dice;
}
void RollN(TDice& Dice)
{
    int temp    = Dice.Top;
    Dice.Top    = Dice.Front;
    Dice.Front  = Dice.Bottom;
    Dice.Bottom = Dice.Back;
    Dice.Back   = temp;
}
void RollE(TDice& Dice)
{
    int temp    = Dice.Top;
    Dice.Top    = Dice.Left;
    Dice.Left   = Dice.Bottom;
    Dice.Bottom = Dice.Right;
    Dice.Right  = temp;
}
void RollW(TDice& Dice)
{
    int temp    = Dice.Top;
    Dice.Top    = Dice.Right;
    Dice.Right  = Dice.Bottom;
    Dice.Bottom = Dice.Left;
    Dice.Left   = temp;
}
void RollS(TDice& Dice)
{
    int temp    = Dice.Top;
    Dice.Top    = Dice.Back;
    Dice.Back   = Dice.Bottom;
    Dice.Bottom = Dice.Front;
    Dice.Front  = temp;
}

void Roll(char c, TDice& Dice)
{
    switch(c){
    case 'N': RollN(Dice); break;
    case 'E': RollE(Dice); break;
    case 'W': RollW(Dice); break;
    case 'S': RollS(Dice); break;
    }
}
int main()
{
    TDice Dice = MakeDice(std::cin);
    std::string s;
    std::cin >> s;
    for(int i = 0; i < s.size(); ++i){
        Roll(s[i], Dice);
    }
    std::cout << Dice.Top << std::endl;
    return 0;
}