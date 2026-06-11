#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> P(N),Q(N);
  vector<int> v(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
  }
  for(int i=0;i<N;i++){
    cin >> Q[i];
    v[i]=i+1;
  }
  int j=1;
  int a,b;
  do{
    if(P==v) a=j;
    if(Q==v) b=j;
    j++;
  }while(next_permutation(v.begin(),v.end()));
  cout << abs(a-b) << endl;
}

