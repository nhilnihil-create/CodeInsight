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

  int n,k,rep=0,d,a;
  std::vector<int> v;
  set<int> s;
  cin>>n>>k;
  for(int i=0 ; i<k ; i++){
      cin>>d;
      for(int j=0 ;j<d ; j++){
        cin>>a;
        s.insert(a);
      }
  }
  cout<<n-s.size()<<endl;



  return 0 ;
}
