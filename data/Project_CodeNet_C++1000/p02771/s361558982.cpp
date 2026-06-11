#include<bits/stdc++.h>
#define FOR(i,x) for(i=1;i<=x;i++)
using namespace std;
using ll = long long int;
typedef vector<ll> vi;
ll k,b,ar[11]={};
void IsEqual()
{
  FOR(b,3){
  	cin>>k;
  	ar[k]++;
  }
  cout<<(*max_element(ar,ar+11)==2?"Yes":"No")<<"\n";
}
int main()
{
    IsEqual();
	return 0;
}