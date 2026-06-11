#include <bits/stdc++.h>
#define for0(i,b) for(int i=0 ; i< b ;i++)
#define for1(i,b) for(int i=1 ; i<=b ;i++)
#define reps(i,a,b) for(int i=a ; i< b.length() ;i++)
typedef long long ll;
#define MOD 1000000007

using namespace std;




int main()
{
    int n,val;
    cin >> n;
    std::vector<int> v(n+1, 0);

    for(int i=2; i<=n ; i++){
      cin >> val;
      v[val]++;
    }

    for(int i=1; i<=n ; i++)
      cout << v[i]<<endl;


  return 0 ;
}
