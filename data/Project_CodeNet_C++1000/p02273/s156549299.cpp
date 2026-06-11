#include <iostream>
#include <cmath>
using namespace std;

struct TPoint{
    double x;
    double y;
};

void Cal(TPoint P1, TPoint P2, int Num);

void Cal(TPoint P1, TPoint P2, int Num)
{
    if(Num == 0)    return;
    
    TPoint Temp1, Temp2, Temp3;

    Temp1.x = (2 * P1.x + P2.x) / 3;
    Temp1.y = (2 * P1.y + P2.y) / 3;
    Temp3.x = (P1.x + 2 * P2.x) / 3;
    Temp3.y = (P1.y + 2 * P2.y) / 3;
    Temp2.x = (Temp3.x - Temp1.x) * cos(60 * M_PI / 180) - (Temp3.y - Temp1.y) * sin(60 * M_PI / 180) + Temp1.x;
    Temp2.y = (Temp3.x - Temp1.x) * sin(60 * M_PI / 180) + (Temp3.y - Temp1.y) * cos(60 * M_PI / 180) + Temp1.y;
    
    Cal(P1, Temp1, Num - 1);
    cout << Temp1.x << " " << Temp1.y << endl;
    Cal(Temp1, Temp2, Num - 1);
    cout << Temp2.x << " " << Temp2.y << endl;
    Cal(Temp2, Temp3, Num - 1);
    cout << Temp3.x << " " << Temp3.y << endl;
    Cal(Temp3, P2, Num - 1);
}

int main(void){
    int Number;
    std::cin >> Number;
    
    TPoint P1, P2;
    
    P1.x = 0; 
    P1.y = 0;
    P2.x = 100;
    P2.y = 0;
    
    cout << P1.x << " " << P1.y << endl;
    Cal(P1, P2, Number);
    cout << P2.x << " " << P2.y << endl;
}