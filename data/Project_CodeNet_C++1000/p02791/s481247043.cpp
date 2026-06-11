#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int p[200100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int count = 0;
    int minimum = 1001001001;
    for(int i = 0; i < n; i++)
    {
        minimum= min(minimum, p[i]);
        if(minimum == p[i])
            count++;
    }
    cout << count << endl;
}
