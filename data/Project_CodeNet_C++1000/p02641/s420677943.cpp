#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x,n,i=0,j,c=0,p,mita[1000] ={0};
    cin >> x >> n;
    for(i=0;i<n;i++)
    {
        cin >> p;
        mita[p]=1; 
    }
    if(mita[x]==0)
    {
        cout << x << endl;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        if(mita[x-i]==0)
        {
            cout << x-i << endl;
            return 0;
        }
        if(mita[x+i]==0)
        {
            cout << x+i << endl;
            return 0;
        }
    }
    cout << x << endl;
    return 0;

}
