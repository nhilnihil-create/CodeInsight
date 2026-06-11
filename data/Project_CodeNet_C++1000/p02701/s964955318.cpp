#include <bits/stdc++.h>
#define rep0(i,b) for(int i=0 ; i< b ;i++)
#define rep1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007
# define M_PI     3.14159265358979323846

using namespace std;


int main()
{
  int n,sum=0;
  string str;
  std::map<string, int> map;
  cin >>n;
  rep0(i,n){
    cin >> str;
    if(!map.count(str))
        map[str] = 1;
  }

  for(auto const& x : map)
    sum += x.second;

  cout<<sum;

  return 0 ;
}
