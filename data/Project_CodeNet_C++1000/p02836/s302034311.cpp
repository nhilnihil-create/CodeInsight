#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string A,B;
    cin >> A;
    B=A;
    reverse(B.begin(),B.end());
    int count=0;
    int C=A.size();
    for(int i=0; i<C/2; i++)
    {
        if(!(A.at(i)==B.at(i)))
        {
            count++;
        }
    }
    cout << count <<endl;
}