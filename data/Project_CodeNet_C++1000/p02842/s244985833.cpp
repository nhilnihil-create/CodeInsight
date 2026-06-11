#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n ; cin>> n;   
    bool checker = false ;
    for(int i = 1 ; i < 50001 ; i++)
    {
        int a = i*1.08 ;
        if(a==n)
        {
            checker = true;
            cout << i << endl;
            break;
        }
        if(a>n) break;
    }
    if(!checker) cout << ":(" << endl;
    return 0 ;
}