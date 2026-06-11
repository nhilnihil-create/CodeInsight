/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int main(){
  vector<int> hon = {2, 4, 5, 7, 9};
  vector<int> pon = {0, 1, 6, 8};
  int n;cin>>n;
  n %= 10;
  if(count(hon.begin(), hon.end(), n)!=0)cout<<"hon"<<endl;
  else if(count(pon.begin(), pon.end(), n)!=0)cout<<"pon"<<endl;
  else cout<<"bon"<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
