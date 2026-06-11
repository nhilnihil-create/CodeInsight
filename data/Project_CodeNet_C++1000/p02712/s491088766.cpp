    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;

    int main()
    {
unsigned ll n,c=0;
cin>>n;
// a[n];
for(unsigned ll i=1;i<=n;i++)
{

    if(i%3!=0 && i%5!=0) {c+=i;}
}
cout<<c;
          return 0;
    }
