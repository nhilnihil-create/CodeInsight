#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll a[40001000];
//ll number[20],used[20];
int main()
{
    string a,b,c;
    cin >> a;
    ll count =0;
    for(ll i=0;i<a.size();i++)
    {
        if(i%2==0)
        {
            if(a[i]=='R'|| a[i]=='U'|| a[i]=='D')
                count =0;
            else
            {
                count =1;
                break;
            }
        }
        else if(i%2!=0)
        {
            if(a[i]=='L'|| a[i]=='U'|| a[i]=='D')
                count =0;
            else
            {
                count =1;
                break;
            }
        }
    }
    if(count==0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
