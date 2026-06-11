#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p,cnt=0;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p;
        if(p != i)
        cnt++;
    }

    if(cnt <=2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
   return 0;
}
