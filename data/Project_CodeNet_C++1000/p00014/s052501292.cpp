#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<utility>
#include<string>

using namespace std;

main(){
  int d;
  int s;
  while(cin >> d){
    s=0;
    for(int i=1;i<600/d;i++) s+=d*i*d*i*d;
    cout << s << endl;
  }
}