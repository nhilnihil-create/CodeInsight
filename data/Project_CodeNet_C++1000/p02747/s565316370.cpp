#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int x = s.length();
    if(x%2!=0)
    {
        cout << "No";
        return 0;
    }
    for(int i = 0; i < x; i++)
    {
        if(i%2==0)
        {
            if(s[i] == 'h')
                ;
            else
            {
                cout << "No";
                return 0;
            }
        }
        else
        {
            if(s[i] == 'i')
                ;
            else
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}
