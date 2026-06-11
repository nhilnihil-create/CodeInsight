#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a[10000],i,c=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            if(a[i]%3==0 || a[i]%5==0)
            {}
            else
            {
                c++;
            }
        }
    }
    if(c==0)
    {
        cout << "APPROVED" << endl;
    }
    else
    {
        cout << "DENIED" << endl;
    }
    return 0;

}
