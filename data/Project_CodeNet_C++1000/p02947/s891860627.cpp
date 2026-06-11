/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}


bool sortByVal(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second < b.second);
}


int main(){

 int n;
 cin>>n;

  map<string,long long>mp;

  for(int i=0;i<n;i++){

     string s;
     cin>>s;
     sort(s.begin(),s.end());
     mp[s]++;
  }

    long long cnt=0;
  for(map<string,long long>::iterator it = mp.begin();it!= mp.end();it++){
    long long y = it->second;
    //cout<<it->second<<endl;
    cnt += (y)*(y-1)/2;
  }

 cout<<cnt<<endl;

return 0;
}

