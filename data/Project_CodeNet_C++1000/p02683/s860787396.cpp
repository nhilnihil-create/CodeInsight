#include<bits/stdc++.h>
using namespace std;

bool provera(vector<long long> &niz,int &m,long long &x)
{
    for (int i=0;i<m;i++)
        if(niz[i]<x)
            return false;
    return true;
}

long long f(vector<vector<long long>> &v,vector<long long> &cene,int &n,int &m,long long &x,vector<long long> niz,int index,long long cena)
{
    if(index==n)
    {
        if(provera(niz,m,x))
            return cena;
        else
            return LLONG_MAX;
    }
    long long m1,m2;
    m1=f(v,cene,n,m,x,niz,index+1,cena);
    for (int i=0;i<m;i++)
        niz[i]+=v[index][i];
    cena+=cene[index];
    m2=f(v,cene,n,m,x,niz,index+1,cena);
    return min(m1,m2);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    long long x,resenje;
    cin >> n >> m >> x;
    vector<long long> cena(n);
    vector<vector<long long>> v(n,vector<long long>(m));
    for (int i=0;i<n;i++)
    {
        cin >> cena[i];
        for (int j=0;j<m;j++)
            cin >> v[i][j];
    }
    vector<long long> niz(m,0);
    resenje=f(v,cena,n,m,x,niz,0,0);
    if(resenje==LLONG_MAX)
        cout << -1;
    else
        cout << resenje;
}
