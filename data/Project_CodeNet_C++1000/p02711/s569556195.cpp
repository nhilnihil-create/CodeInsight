#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string num;

    cin >> num;

    for(int i=0; i<num.size(); i++)
    {
        if(num[i] == '7')
        {
            cout << "Yes";
            return 0;
        }
    }
    
    cout << "No";


}
