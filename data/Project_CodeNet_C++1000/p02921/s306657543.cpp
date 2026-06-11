#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S,M;
    cin >> S >> M;
    int count=0;
    for(int i=0; i<3; i++)
    {
        if(S.at(i)==M.at(i))
        {
            count++;
        }
    }
    cout << count <<endl;
}
