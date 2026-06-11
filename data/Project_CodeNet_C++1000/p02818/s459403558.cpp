
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(inti=a;i<=b;i++)

typedef long long int ll;
typedef vector<int>vi;
typedef pair<int,int>pi;



int main()
{
ll a,b,k;
cin>>a>>b>>k;

cout<<max(0LL,a-k)<<" "<<max(b-(max(0LL,k-a)),0LL)<<endl;
 return 0;
}
