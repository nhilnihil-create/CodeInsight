#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool chk=true;
    string S;
    cin >> S;
    if(S.at(0)==S.at(1)) chk=false;
    if(S.at(2)==S.at(1)) chk=false;
    if(S.at(2)==S.at(3)) chk=false;
    if(chk) cout << "Good" << endl; else cout << "Bad" << endl;
}
