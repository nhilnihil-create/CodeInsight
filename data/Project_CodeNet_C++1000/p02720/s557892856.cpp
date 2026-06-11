#include<bits/stdc++.h>
using namespace std;
long long int a[100010], temp, i, j, k, l;
int main()
{
    cin >> k;
    for(i=1;i<10;i++)
    {
        a[j++] = i;
    }
    while(j<=k)
    {
        temp = a[l++];
        if(temp%10!=0)
            a[j++] = temp*10 + (temp%10-1);
        a[j++] = temp*10 + temp%10;
        if(temp%10!=9)
            a[j++] = temp*10 + (temp%10+1);
    }
    cout << a[k-1] << endl;
    return 0;
}
