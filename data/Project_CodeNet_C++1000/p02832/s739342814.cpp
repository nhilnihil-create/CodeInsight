
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

int n;
cin>>n;

int ans = 0;
int i =1;
for(int index =0;index<n;index++)
{
    int c;
    cin>>c;

    if(c!=i)ans++;
    else i++;
}
if(ans==n)
    cout<<-1<<endl;
else
    cout<<ans<<endl;


 return 0;
}
