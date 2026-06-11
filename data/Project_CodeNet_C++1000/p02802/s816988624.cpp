

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long lNsong for now.
Add something here.

*/
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100005];;

ll gcd(long long a,long long b){

  if(b == 0)
    return a;
  else return gcd(b,a%b);
}

bool compare(pair<int,int>p1, pair<int,int>p2){

  return p1.second > p2.second;
 }

 // sorting the map when the first is string ans second is the integer
 bool sortbyval(pair<string,int>a, pair<string,int>b){
   return a.second < b.second;
 }

int main(){

  long long n,m,right=0,wrong=0;
  long long p;
  string a;
  cin>>n>>m;

  set<long long>ani;
  map<int,int>times;

    while(m--)
   {
       cin>>p>>a;
      // times[p]++;
        if(a == "WA")
            times[p]++;
        else if(a == "AC"){
            if(ani.find(p) == ani.end()){
              right++;
              wrong += times[p];
            ani.insert(p);
            }
        }

    }

    cout<<right<<" "<<wrong<<endl;

 return 0;
}
