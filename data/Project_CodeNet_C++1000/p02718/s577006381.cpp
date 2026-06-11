#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int A[1];
int size=1;
int m=2;
#define N 101
#define mod 1000000007
#define f(i,n) for(int i=0;i<n;i++)
/*
bool prime(ll n){if(n==1)return false;for(ll i=2;i*i<=n;i++)if(n%i==0){return false;}return true;}
void prime_fact(int n){for(int i=2;i*i<=n;i++){int count=0;if(n%i==0){while(n%i==0)n/=i,count++;cout<<i<<"^"<<count<<" ";}}if(n>1)cout<<n<<"^1";}
ll power(ll base ,ll pow){ll res=1;while(pow>0){if(pow&1)res*=base,pow-=1;else base*=base,pow/=2;}return res;}
void prime_fact_seieve(int n){for(int i=2;i<=size;i++){if(A[i]==0)for(ll j=i;j<=size;j+=i)if(A[i]==0)A[j]=i;}while(n>2){cout<<A[n]<<"*";n/=A[n];}}
template <class X> X gcd(X a , X b) { return b==0?a: gcd( b, a%b); }
template <class X> X lcm(X a , X b) { return a/gcd(a,b) * b ; }
ll Ab[N][N],I[N][N];  // identity matrix and a matrix to store result
void multiply(ll I[][N],ll A[][N],int dim)
{   int res[dim+1][dim+1];
    for(int i=0;i<dim;i++)
    {  for(int j=0;j<dim;j++)
        {
           res[i][j]=0;
           for(int k=0;k<dim;k++)
           {  res[i][j]+=((I[i][k]%mod)*(A[k][j])%mod)%mod;}}}

        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                I[i][j]=res[i][j];}
void powerMat(ll A[][N],int dim,int n)
{   for(int i=0;i<dim;i++)
    for(int j=0;j<dim;j++)
    {if(i==j) I[i][j]=1;
     else     I[i][j]=0;}
     while(n>0)
     {
         if(n%2)
         multiply(I,A,dim),n--;
         else
         multiply(A,A,dim),n/=2;
     }
     for(int i=0;i<dim;i++)
         for(int j=0;j<dim;j++)
             A[i][j]=I[i][j];
}
void printMat(ll A[][N],int dim)
{
    for(int i=0;i<dim;i++)
    {for(int j=0;j<dim;j++)
        {
            cout<<A[i][j]<<" ";
        }cout<<"\n";}
}
// REMEMBER PREFIX SUM SUFFIX SUM OR GCD VERY INTERESTING QUESTIONS
ll power(ll base ,ll pow,ll mo){ll res=1;while(pow>0){if(pow&1)res=(res%mo*base%mo)%mo,pow-=1;else base=(base%mo*base%mo)%mo,pow/=2;}return res;}*/
bool Binary(vector<int> arr,int n,int ele,int b)
{  int l=0,r=n-1,m;
   while(l<=r)
   {
       m=l+(r-l)/2;
       if(arr[m]==ele)
       {arr[m]=b;return true;}
       else if(arr[m]>ele)
           r=m-1;
       else
           l=r+1;
   }
    return false;

}

int main()
{
    fast;
    int n,m;float sum=0;
    cin>>n>>m;
    int arr[n];
    f(i,n){cin>>arr[i];sum+=arr[i];}
    sum=sum/(4*m);
    //cout<<sum;
    int count=0;
    f(i,n)
    {
        if(arr[i]>=sum)
            count++;
    }
    if(count>=m)
        cout<<"Yes";
    else
        cout<<"No";

}
