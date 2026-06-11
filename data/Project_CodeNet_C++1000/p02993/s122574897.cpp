#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI = (acos(-1));
const long long MOD = pow(10, 9) + 7;
long long kaizyou(int N);
long long POW(int J);

bool judge(int dt, int dx, int dy);

int main()
{
    string s;
    cin >> s;

    bool judge = true;
    for(int i=0; i<s.size()-1;i++ )
    {
        if(s[i] == s[i+1])
        {
            judge = false;
            break;
        }
    }

    if(judge)
    {
        cout << "Good";
    }else
    {
        cout << "Bad";
    }
    
}
