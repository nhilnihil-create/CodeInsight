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

int n ;
cin>>n;

int arr[n];
for(int i = 0 ; i< n ; i++)
    cin>>arr[i];

    int ans = INT_MAX;
for(int pos = 0 ; pos <=100 ; pos++)
{
    int curr = 0 ;
    for(int i = 0 ; i< n ; i++)
     curr+=(arr[i]-pos)*(arr[i]-pos);

     ans= min(ans, curr);
}
std::cout<<ans<<endl;
 return 0;
}
