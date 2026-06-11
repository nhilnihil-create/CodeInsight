#include <bits/stdc++.h>

using namespace std;
int n,m,k,i,j,x,y,a[200005],st=1,dr,mij,sol;
bool verif(int x)
{
    int nr=0;
    for(i=1;i<=n;i++)
        if(a[i]>x)
            nr+=((a[i]-1)/x);
    return nr<=k;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++)
        {
            cin>>a[i];
            dr=max(dr,a[i]);
        }
    while(st<=dr)
    {
        mij=(st+dr)>>1;
        if(verif(mij)){
            sol=mij;
            dr=mij-1;
        }
        else st=mij+1;
    }
    cout<<sol;
    return 0;
}
