//BISMILLAHIR RAHMANIR RAHIM
//SOTO MEAW
//SOTO SONDESH
#include<bits/stdc++.h>

#define ls ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define __ <<" "<<
#define loop(m,n) for(m=0;m<n;m++)
#define case(z) "Case " << z++ << ": "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define quit return 0

using namespace std;

void showmyDS(set<int> ds)
{
    set<int> ::iterator it;
    for (it=ds.begin();it!=ds.end();it++)
    {
        cout << *it << endl ;
    }
    cout << endl;
}
int main()
{
    ls
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //int t,l=1;cin>>t;while(t>0){
        ll int n;
        cin >> n ;
        ll int a[n],i,c=1,mn=INT_MAX;
        loop(i,n)
        {
            cin >> a[i];
            if(i==0)
                mn=a[i];
            else
            {
                if(a[i]<mn)
                {
                    c++;
                    mn=a[i];
                }
            }
        }
        cout<<c;
    //t--;}

    quit;
}