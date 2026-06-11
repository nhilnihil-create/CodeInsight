/***"In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge whom he wants."***/
/*** "ALHAMDULILLAH for Everything..." ***/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, n,i,j,p,m;
    cin>>n;
    vector<double>v;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    p = v[0];
    for(i=1; i<v.size(); i++)
    {

        m = (p + v[i])/2;
        p = m;

    }

    cout<<p<<endl;








    return 0;
}
