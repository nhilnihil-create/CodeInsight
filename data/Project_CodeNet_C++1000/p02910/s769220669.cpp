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

 string s;
 cin>>s;

 for(int i=0;i<s.length();i++)
 {
    if(i%2 == 0){
      if(s[i] == 'R' || s[i] == 'U' || s[i] == 'D')
        continue;
      else {
          cout<<"No"<<endl;
           return 0; }
     }
     else if(i%2 == 1){

        if(s[i] == 'L' || s[i] == 'U' || s[i] == 'D')
          continue;
        else {
            cout<<"No"<<endl;
             return 0;
        }

     }
 }
 cout<<"Yes"<<endl;

 return 0;
}