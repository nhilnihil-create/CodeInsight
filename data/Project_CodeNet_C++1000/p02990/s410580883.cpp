#include<bits/stdc++.h>
#define pb           push_back
#define pf           push_front
#define in           insert
#define ff           first
#define ss           second
#define mp           make_pair
#define int          long long
#define uint         unsigned long long
#define rep(i,x,m)   for(int i=x;i<m;i++)
#define repr(i,x,m)  for(int i=x;i>=m;i--)
#define MOD          1000000007
#define endl         "\n"
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define vi           vector<int>
#define vs           vector<string>
#define pi           pair<int,int>
#define di           deque<int>
#define sz(x)       (int)x.size()
#define pq           priority_queue<int>
#define pqs          priority_queue<int,vi,greater<int> >
#define fix(y)       fixed<<setprecision(y)
#define print(v)     for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl
#define noob         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int fac[2000005]={0};
void factorial(){ fac[0]=1; fac[1]=1; for(int i=2;i<2000005;i++) fac[i]=((i%MOD)*(fac[i-1]%MOD))%MOD;}
int power(int n,int m)
{int p=1;if(m==0)return 1;p=(power(n,m/2)%MOD);p=(p%MOD*p%MOD)%MOD;
return(m&1?((p%MOD*n%MOD)%MOD):(p%MOD));}
int ncr(int n,int r){return (((fac[n]%MOD)*(power(fac[r],MOD-2)%MOD))%MOD*power((fac[n-r])%MOD,(MOD-2)%MOD))%MOD;}

void ram5564()
{
     int n,k;
     cin>>n>>k;
     rep(i,1,k+1)
     {
        //cout<<i<<":";
        int m1=k-i;
        int n1=i;
        int sum1=(ncr(n1+m1-1,m1))%MOD;
        //cout<<sum1<<" ";
        int n2=i-1+2;
        int m2=(n-k)-(i-1);
        if(m1<0||m2<0)
        {
            cout<<0<<endl;continue;
        }
        int sum2=(ncr(n2+m2-1,m2))%MOD;
        //cout<<sum2<<endl;
       
        cout<<(sum1%MOD*sum2%MOD)%MOD<<endl;



     }

}

signed main()
{
        noob
       
        factorial();
        int t=1;
        //cin>>t;
        while(t--)
        ram5564();
        cerr<<"\n"<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;

        return 0;
}