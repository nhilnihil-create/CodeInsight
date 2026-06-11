#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m,d,cnt = 0;
    cin >> m >> d;
    for(int i = 2; i <= m; i++){
        for(int j = 22; j <= d; j++){
            if(j%10 == 1 )
                continue;
            if(i == (j%10)*(j/10))
                cnt++;
        }
    }
    cout<<cnt<<endl;
}
