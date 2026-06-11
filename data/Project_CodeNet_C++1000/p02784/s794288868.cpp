#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
   ll H,N,A,sum=0;
   cin >> H >> N;
   for(int i=0;i<N;i++){
       cin >> A;
       sum+=A;
   }
   if(sum>=H) {
       cout << "Yes" <<endl;
   }
   else{
       cout << "No" << endl;
   }
   
}
