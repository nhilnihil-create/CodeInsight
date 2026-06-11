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

int n ,r ;
cin>>n>>r;

if(n<10)
    cout<<r+100*(10-n)<<endl;
else
    cout<<r<<endl;

 return 0;
}
