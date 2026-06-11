#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,k,i;
    string ans="NG";
    cin >> k >> a >> b;

    for(i=a; i<=b; i++)
    {
        if(i%k == 0){
            ans = "OK";
            break;
        }
    }
    cout << ans << endl;


    return 0;
}