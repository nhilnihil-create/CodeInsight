#include <bits/stdc++.h>
using namespace std;


int main() {

    int N,L;
    cin>>N>>L;


    int taste_sum=0;
    int taste_min=2000;
    for(int i=1;i<=N;i++){
      int wk=L+i-1;
      taste_sum+=wk;
      if(abs(wk)<abs(taste_min)){
        taste_min = wk;
      }
    }

    cout<<taste_sum-taste_min<<endl;
    
    return 0;
}