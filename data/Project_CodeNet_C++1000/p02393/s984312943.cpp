#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

/**
  vector<int>ar(3);
  for(auto&e:ar){
      scanf("%d",&e);
  }
  sort(ar.begin(),ar.end())
  int sum=accumulate(ar.begin(),ar.end(),0);
 **/

int main(){
    double pai=3.141592653589;
    vector<int> ar(3);
    for(auto&e:ar){
        scanf("%d",&e);
    }
    sort(ar.begin(),ar.end());
    printf("%d %d %d\n",ar[0],ar[1],ar[2]);
    return 0;
}