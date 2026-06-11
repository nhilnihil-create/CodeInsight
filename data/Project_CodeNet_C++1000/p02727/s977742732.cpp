#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>a, b, c, Mix;
ll i, aa, bb, cc, x, y, temp, r, g, ans, k;
int main()
{
    cin >> x >> y >> aa >> bb >> cc;
    for(i=0;i<aa;i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(i=0;i<bb;i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    for(i=0;i<cc;i++)
    {
        cin >> temp;
        c.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    for(i=aa-1,k=0;i>=0 && k<x;i--, k++)
        Mix.push_back(a[i]);
    for(i=bb-1, k=0;i>=0 && k<y;i--, k++)
        Mix.push_back(b[i]);
    temp = Mix.size();
    //cout << temp << endl;
    for(i=0;i<x+y-temp;i++)
        Mix.push_back(c[cc-i-1]);

    temp = Mix.size();
    sort(Mix.begin(), Mix.end());
//    for(i=0;i<Mix.size();i++)
//        cout << Mix[i] << endl;
    k = 0;
    for(;i<c.size();i++)
    {
        if(Mix[k]<c[cc-1-i])
        {
            Mix[k] = c[cc-1-i];
            k++;
        }
    }
    for(i=0;i<temp;i++)
        ans += Mix[i];
    cout << ans << endl;
    return 0;
}
