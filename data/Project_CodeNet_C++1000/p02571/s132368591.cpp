#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>

void testcase()
{
    string s1, s2;
    cin >> s1 >> s2;
    int change = INT_MAX,x = 0;
    for (int i = 0; i + s2.length() - 1 < s1.length(); i++)
    {
        x = 0;
        for (int j = 0;j < s2.length(); j++)
        {
            if(s1[i + j] != s2[j]){
                // cout << s1[i + j] << " " << s2[j ] << "\n";
                x++;
            } 
        }
        change = min(change,x);
    }
    cout << change << " ";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    testcase();
    return 0;
}
