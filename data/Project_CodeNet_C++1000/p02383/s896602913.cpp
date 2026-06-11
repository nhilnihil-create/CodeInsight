#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
class dice
{
public:
    dice()
    {

    }
    int n[6];
    void set(int n0,int n1,int n2,int n3,int n4,int n5)
    {
        n[0] = n0;
        n[1] = n1;
        n[2] = n2;
        n[3] = n3;
        n[4] = n4;
        n[5] = n5;
    }
    int get(int i)
    {
        return n[i];
    }
    int rot(char c)
    {
        int t[6];
        for(int i = 0;i < 6;i++)
        {
            t[i] = n[i];
        }
        switch(c)
        {
        case 'N':
            n[0] = t[1];
            n[1] = t[5];
            n[5] = t[4];
            n[4] = t[0];
            break;
        case 'S':
            n[0] = t[4];
            n[1] = t[0];
            n[5] = t[1];
            n[4] = t[5];
            break;
        case 'E':
            n[0] = t[3];
            n[3] = t[5];
            n[5] = t[2];
            n[2] = t[0];
            break;
        case 'W':
            n[0] = t[2];
            n[3] = t[0];
            n[5] = t[3];
            n[2] = t[5];
            break;
        default:
            break;
        }
    }
};

int main()
{
    int n[6];
    for(int i= 0;i < 6;i++)
    {
        cin >> n[i];
    }
    dice d;
    d.set(n[0],n[1],n[2],n[3],n[4],n[5]);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        d.rot((char)s.at(i));
    }
    cout << d.get(0) << endl;
    return 0;
}