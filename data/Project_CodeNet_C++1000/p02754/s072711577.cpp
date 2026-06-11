#include<bits/stdc++.h>
#define PB push_back
#define FO(i,a,b) for (int i = a; i <= b; i++)
#define FOb(i,a,b) for(int i=b;i>=a;i--)
#define vi vector<int>
#define vulli vector<unsigned long long int>
using namespace std;
typedef unsigned long long int ulli;
void solve()
{ 
  ulli n,a,b;
  cin >> n >> a >> b;
  ulli count_both = n / (a+b);
  ulli count = count_both*a;
  ulli left = n % (a+b);
  if (left >= (a))  count += a;
  else  count += (left%(a+b));
  cout << count ;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    ulli t=1;
   // cin>>t;   
    while(t--){ solve(); cout<<"\n"; }
    return 0;
}