#include<iostream>
using namespace std;
int main()
{
    int l;
    cin >> l;

    string s;
    cin >> s;

    int count=0;
    for(int i=1; i<(l-1) ; i++)
    {
        if(s[i-1] == 'A' && s[i] == 'B' && s[i+1] == 'C')
            count++;
    }
    cout << count << endl;

    return 0;
}