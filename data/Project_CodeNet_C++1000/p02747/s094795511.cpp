#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
  string s;
  cin>>s;
  int N=s.size();
  if(N%2!=0) {
      cout<<"No"<<endl;
      return 0;
  }
  rep(i,N) {
      if(i%2==0&&s[i]!='h') {
          cout<<"No"<<endl;
          return 0;
      }
      else if(i%2==1&&s[i]!='i') {
          cout<<"No"<<endl;
          return 0;
      }
  }
  cout<<"Yes"<<endl;
  return 0;
}