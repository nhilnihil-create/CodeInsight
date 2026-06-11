#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,b,ans;

    cin >> a >> b;

    if((a+b)%2 != 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    ans = (a+b)/2;
    cout << ans << endl;

   return 0;
}