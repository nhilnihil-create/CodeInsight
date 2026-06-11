#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;

int main()
{
    ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin>>n;
  string s;
  while(n){
    if(n%26==0){s.push_back('z');
    n=n/26;
    n--;
    }
    else{s.push_back((char)('a'+n%26-1));
    n=n/26;
    }
  }
  reverse(s.begin(),s.end());
  cout<<s;
    return 0;
}