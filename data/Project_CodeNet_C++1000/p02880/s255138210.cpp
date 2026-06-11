//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans=0;
    long long  n;
    cin >> n;
    for(int i=1; i<10; i++)
    {
       for(int j=1; j<10; j++)
        {
            if (i*j == n)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

}


