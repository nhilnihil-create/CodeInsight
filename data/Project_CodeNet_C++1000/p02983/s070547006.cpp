#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int l,r,MOD=2019,min=50000000000,i,j;
    cin >> l >> r;
    for(i=l;i<r;i++)
    {
        for(j=i+1;j<=r;j++)
        {
            if(min>(i%MOD)*(j%MOD)%MOD)
            {
                min=(i%MOD)*(j%MOD)%MOD;
            }
            if(min==0)
            {
                cout << min << endl;
                return 0;
                break;
            }
        }
    }
    cout << min << endl;
                                    
    return 0;

}
