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

int main()
{
    string s;
    cin >> s;

    set<char> c;
    int sum=0;
    const int N=4;
    int num[4] = {};

    for(int i=0; i<N-1; i++)
    {
        for(int j= i+1; j<N; j++)
        {
            if(s[i] == s[j])
            {
                c.insert(s[i]);
                num[i]++;
                sum++;
            }
        }
    }

    bool judge = true;
    int test=0;
    
    for(int i=0; i<N-1; i++)
    {
        if(s[i] > 1)
        {
            judge = false;
        }

    }

    if(c.size() == 2 && sum == 2 )
    {
        if(sum = 2)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}
