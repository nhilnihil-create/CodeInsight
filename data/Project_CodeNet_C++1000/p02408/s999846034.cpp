#include <iostream>
using namespace std;

int main()
{
    const int kOneTypeCardNum = 13;
    const int kTypeNum = 4;
    const char kCardChar[kTypeNum] = {'S','H','C','D'};

    bool isHad[kTypeNum][kOneTypeCardNum] = {false};
    int num=0, no=0;
    char type;

    cin >> num;
    for (int i=0; i<num; ++i)
    {
        cin >> type >> no;
        for (int j=0; j<kTypeNum; ++j)
        {
            if (type == kCardChar[j])
            {
                isHad[j][no-1] = true;
                break;
            }
        }
    }
    
    for (int i=0; i<kTypeNum; ++i)
    {
        for (int j=0; j<kOneTypeCardNum; ++j)
        {
            if (!isHad[i][j])   cout << kCardChar[i] << ' ' << j+1 << endl;
        }
    }
    
    return 0;
}