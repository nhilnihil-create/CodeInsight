#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n,d,x,y,i;
    int cnt=0;

    cin >> n >> d ;

    for(i=0; i<n; i++){
        cin >> x >> y;

        if(sqrt(x*x + y*y) <= d )
            cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}