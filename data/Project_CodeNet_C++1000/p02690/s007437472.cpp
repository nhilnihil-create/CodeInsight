
#include<bits/stdc++.h>
using namespace std;

int32_t main( )        {

    int N;
    cin>>N;

    for(int i=-200;i<=200;i++)    {
        for(int j=-200;j<=200;j++) {
            if(pow(i,5)-pow(j,5)==N) {
                cout<<i<<" "<<j;
                return 0;
            }

        }
    }

return 0;
}
