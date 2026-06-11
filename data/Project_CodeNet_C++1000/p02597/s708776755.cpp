#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long mx(long long a,long long b){if(a>b)return a;else return b;}
long long mn(long long a,long long b){if(a<b)return a;else return b;}
long long cei(long long a,long long b){if(a%b==0)return a/b;else return (a/b+1);}
const int MOD=1e9+7;
long long po(long long a,long long b){long long res=1;while(b>0){res=(res*a);res%=MOD;b--;}return res;}
int main()
{
int n;
cin>>n;
string a;
cin>>a;
int rcount=0;
int count=0;
vector<int>rindices;
for(int i=0;i<n;i++)
{
if(a[i]=='R'){rcount++;rindices.push_back(i);}
}
int j=rindices.size()-1;
int i=0;
rcount--;
while(i<n&&j>=0)
{
if(a[i]=='W'&&rindices[j]>rcount){count++;j--;}
i++;
}
if(rcount==-1||rcount==n)cout<<0<<endl;
else
cout<<count<<endl;
}