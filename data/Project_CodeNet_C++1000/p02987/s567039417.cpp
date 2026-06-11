#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool chk=false;
    string A;
    cin >> A;
    sort(A.begin(),A.end());
    if((A.at(0)==A.at(1))&&(A.at(2)==A.at(3))&&(!(A.at(1)==A.at(2))))
    {
        chk=true;
    }
    if(chk)
    {
        cout << "Yes" <<endl;
    }
    else
    {
        cout << "No" << endl;
    }
}