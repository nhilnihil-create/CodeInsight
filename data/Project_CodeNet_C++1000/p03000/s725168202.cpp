#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(void)
{
    int a,b;
    cin >> a >> b;
    int val, counter = 1, i, sum = 0;
    for(i = 0; i < a; i++)
    {
        cin >> val;
        sum += val;
        if(sum <= b)
            counter++;
    }
    cout << counter << endl;

    return 0;
}
