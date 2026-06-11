
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

bool isprime(int x)
{

    int n=sqrt(x);
    for(int i = 2;i<=n;i++)
        if(x%i==0)
        return false;
    return true;
}

int main()
{
int x;
cin>>x;

while(!isprime(x))
    x++;

    cout<<x<<endl;
 return 0;
}
