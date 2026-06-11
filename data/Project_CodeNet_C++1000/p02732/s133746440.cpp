#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i, temp,t, n,j, a[200600], ans, sum;
bool cond;
map<ll,ll>C;
map<ll,pair<ll,ll> >Ans;
vector<int>V;
bool vis[200010];
string s;
int main()
{
    //I am Monim, a tiny creature of Allah
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> temp;
        a[i] = temp;
        if(!vis[temp])
        {
            V.push_back(temp);
            vis[temp] =  true;
        }
        C[temp]++;
    }
    sum = 0;
    for(i=0;i<V.size();i++)
    {
        sum += (C[V[i]]*(C[V[i]]-1))/2;
    }
    for(i=0;i<n;i++)
    {
        cout << sum - (C[a[i]]*(C[a[i]]-1))/2 + ((C[a[i]]-1)*(C[a[i]]-2))/2 << endl;
    }
    return 0;
}
