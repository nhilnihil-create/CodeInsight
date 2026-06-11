#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int a[n];

    int i;

    int cnt=0;

    for(i=1;i<=n;i++)
    {
        cin >> a[i];

        if(i>1)
        {
            if(a[i]<=a[i-1])
            {
                cnt++;
            }
            else
            {
                a[i]=a[i-1];
            }
        }
    }



    cout << ++cnt<< endl;

    return 0;
}
