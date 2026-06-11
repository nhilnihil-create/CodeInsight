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

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);
    int x = power(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}
bool isprime(int n, int k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;
    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++)
         if (!miillerTest(d, n))
              return false;
    return true;
}
int main()
{
    ls
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ll int t,l=1;cin>>t;while(t>0){
        ll int a,b,c,d,sum=1;
        cin >> a >> b >> c >> d ;
        sum=b*d;
        if(sum<a*d) sum=a*d;
        if(sum<a*c) sum=a*c;
        if(sum<b*c) sum=b*c;
        cout << sum ;
    //t--;}
    quit;
}
