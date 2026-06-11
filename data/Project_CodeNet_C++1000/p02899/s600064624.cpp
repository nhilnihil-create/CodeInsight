#include <bits/stdc++.h>
#define FLASH ios_base::sync_with_stdio(0);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";


using namespace std;


ll massiv[100010];
ll n;

int main(){
FLASH;
cin>>n;
for(ll i=1;i<=n;i++)
{
  ll x;
  cin>>x;
  massiv[x]=i;
}

for(ll i=1;i<=n;i++)cout<<massiv[i]<<" ";
cout<<endl;





return 0;
} 
