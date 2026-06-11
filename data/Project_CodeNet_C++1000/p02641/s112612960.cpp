#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    int x, n;
    cin >> x >> n;
    int *p = new int[n];
    for (int i = 0; i < n;i++)
    {
        cin >> p[i];
    }

    int sml = INT_MAX;
    int lar = INT_MIN;
    int flag = 0;
    for (int i = 0; i <= n;i++)
    {
        flag = 1;
        for (int j = 0; j < n;j++)
        {
            if(x-i==p[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            sml = x - i;
            break;
        }
    }
    for (int i = 0; i <= n;i++)
    {
        flag = 1;
        for (int j = 0; j < n;j++)
        {
            if(x+i==p[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            lar = x + i;
            break;
        }
    }
    if((lar-x)<(x-sml))
    {
        cout << lar << endl;
    }else
    {
        cout << sml << endl;
    }
    return 0;
}