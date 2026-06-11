#include<iostream>
#include<string>
using namespace std;

int main()
{
    bool con = false;
    string n;
    cin >> n;

    for(int i = 0; i < n.size(); i++)
    {
        if(n[i] == '7')
            con = true;
    }

    if(con)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
