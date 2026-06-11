#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin  >> n;
    string str;
    cin >> str;
    vector <ll> R;
    vector <ll> G;
    vector <ll> B;
    for(ll i=0;str[i]!='\0';i++)
    {
        if(str[i]=='R')
        {
            R.push_back(i);
        }
        else if(str[i]=='G')
        {
            G.push_back(i);
        }

        else if(str[i]=='B')
        {
            B.push_back(i);
        }
    }
    long long int R_size=R.size();
    long long int G_size=G.size();
    long long int B_size=B.size();
    long long int arr[B_size];
    long long int ans=R_size*G_size*B_size;
//    long long int minus=0;
    vector<ll>check;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int k = 2*j - i;
            if(k < n && str[i] != str[j] && str[j] != str[k] && str[i] != str[k])
                ans--;

        }

    }
    //ans-=minus;
    //cout << minus<<"\n";
    cout << ans;
}
