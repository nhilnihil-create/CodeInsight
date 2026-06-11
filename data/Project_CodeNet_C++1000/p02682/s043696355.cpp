#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int a[N],b[N];
list<char>v;
map<char,int>mp;
int main()
{
   Run();
    ll A,B,C,K;
  cin>>A>>B>>C>>K;
  if(K<=A) {
cout<<K<<endl;
    return 0;
  }
  else if(K>A+B) {
cout<<2*A+B-K<<endl;
  }
  else {
cout<<A<<endl;
  }
}

