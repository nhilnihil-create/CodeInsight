#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m,i=0,j,s,x[10000],min=1000000,goukei=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x[i];
    }
    for(i=0;i<105;i++)
    {
        goukei=0;
        for(j=0;j<n;j++)
        {
            goukei+=abs(x[j]-i)*abs(x[j]-i);
        }
        if(min>goukei)
        {
            min=goukei;
        }
    }
    cout << min << endl;
    return 0;

}
