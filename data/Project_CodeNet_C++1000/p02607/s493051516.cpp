#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){

int n,count=0;

cin >> n;

std::vector<int> a(n);

for(int i=1;i<=n;i++){
  cin >> a.at(i-1);
  if(a.at(i-1)%2==1 && i%2==1){
    count++;
  }
}



cout << count << endl;

}
