//BISMILLAHIR RAHMANIR RAHIM
//SOTO MEAW
//SOTO SONDESH
#include<bits/stdc++.h>

#define ls ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define __ <<" "<<
#define loop(m,n) for(m=0;m<n;m++)
#define rloop(m,n) for(m=n-1;m>=0;m--)
#define case(z) "Case " << z++ << ": "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define newline cout<<endl
#define quit return 0

using namespace std;

bool isprime(int n)
{
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

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
    //int t,l=1;cin>>t;while(l>0){
        int n;
        cin>>n;
        int num,k,i,j,l,r;
        int c[10][10]={0};
        for(i=1;i<=n;i++)
        {
            r=i%10;
            num=i;
            while(num!=0)
            {
                k=num%10;
                num/=10;
            }
            l=k;
            c[l][r]++;
        }
        ll int total = 0;
        loop(i,10){
            loop(j,10){
                total+=(c[i][j]*c[j][i]);
            }
        }
        cout<<total;
        newline;
    //t--;}

    quit;
}
