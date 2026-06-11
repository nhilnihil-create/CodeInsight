#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    vector<int> line;
    char temp;
    cin >> n >> k;
    
    cin >> temp;
    line.push_back(temp);
    int happyGuy = 0;
    for(int i = 1; i < n; ++i)
    {
        cin >> temp;
        if(line[i - 1] == temp)
            ++happyGuy;
        line.push_back(temp);
    }

    cout << min(happyGuy + 2 * k, n - 1) << endl;
}