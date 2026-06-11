#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define ull unsigned long long
#define mp make_pair
using namespace std;

#define mmm    ios_base::sync_with_stdio(false);cin.tie(NULL);

int main() {
mmm
ll n,sum=0; cin>>n;

for(ll i=1; i<=(n-1); i++)
{
	sum+=(n-1)/i;
}
cout<<sum<<endl;
    return 0;
}