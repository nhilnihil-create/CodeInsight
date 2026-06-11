
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

int n , x;
cin>>n>>x;

int arr[n+1];
arr[0]=0;
int ans =0;
for(int index = 1 ;index <= n;index++)
{
    int c ;
    cin>>c;

    arr[index]=arr[index-1]+c;
    if(arr[index]<=x)
        ans = index;
}
cout<<ans+1<<endl;


 return 0;
}
