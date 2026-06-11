#include<bits/stdc++.h>
using namespace std;
#define mod int(1e+9+7)
using ll=long long;

int main()
{
    int N;cin >> N;
    vector<int> colors(3,0);
    ll ans=1;
    int input;
    for (int i=0;i<N;i++)
    {
        cin >> input;
        int count=0;
        int index;
        for (int j=0;j<3;j++)
        {
            if (colors[j]==input)
            {
                count++;
                index=j;
            }
        }
        ans*=count;
        ans%=mod;
        colors[index]++;
    }
    cout << ans << endl;
    return 0;
}