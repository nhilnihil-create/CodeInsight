#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int cnt=0;

void Divisors(int n)
{
    vector<int>v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(),v.end());
    //for(int i=0; i<v.size(); i++)
    //cout<<v[i]<<" ";
    for(int i=0; i<v.size(); i++)
    {
        if(mp[v[i]])
        {
            if(v[i]==n)
            {
                if(mp[n]>1)
                {
                    cnt++;
                    break;
                }
            }
            else
            {
                cnt++;
                break;
            }
        }
    }

}

int main()
{
    int n, x, i;
    cin >> n;
    int a[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    for (int i=0; i<n; i++)
    {
        Divisors(a[i]);

    }
    cout<<n-cnt<<endl;
}
