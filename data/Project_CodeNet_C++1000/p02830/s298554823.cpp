
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

string s,t;
cin>>s>>t;

for(int index = 0 ; index <n ; index++)
{
    cout<<s[index]<<t[index];
}
cout<<endl;

 return 0;
}
