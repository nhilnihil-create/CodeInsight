#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   string S;
   cin >> S;
   int size = S.size();
   int ans[size];
   memset(ans,0,sizeof(ans));
   for(int i = 0 ; i < size; i++){
      if(S[i]=='R'){
         int j = i;
         while(S[j]=='R'){
            j++;
         }
         int dist = j-i;
         int iN = (dist+1)/2;
         int jN = dist/2;
         if(dist%2==0){
            ans[j]+=iN;
            ans[j-1]+=jN;
         }
         else{
            ans[j-1]+=iN;
            ans[j]+=jN;
         }
         i=j-1;
      }
   }
   for(int i = size-1 ; i >= 0; i--){
      if(S[i]=='L'){
         int j = i;
         while(S[j]=='L'){
            j--;
         }
         int dist = i-j;
         int iN = (dist+1)/2;
         int jN = dist/2;
         if(dist%2==0){
            ans[j]+=iN;
            ans[j+1]+=jN;
         }
         else{
            ans[j+1]+=iN;
            ans[j]+=jN;
         }
         i=j+1;
      }
   }
   for(int i=0;i<size;i++){
      cout << ans[i] << " " ;
   }
   cout << endl;
   return 0;
}
