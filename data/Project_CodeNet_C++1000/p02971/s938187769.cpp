#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a[200010],n,i,saidai=0,c=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(saidai<a[i])
        {
            saidai=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i]==saidai)
        {
            c++;
        }
    }
    if(c>=2)
    {
        for(i=0;i<n;i++)
        {
            {
                cout << saidai << endl;
            }
        }
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(a[i]!=saidai)
        {
            cout << saidai << endl;
        }
        else
        {
            sort(a,a+n,greater<int>());
            cout << a[1] << endl;
        }
    }
    return 0;
}
