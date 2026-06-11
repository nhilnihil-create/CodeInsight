#include <bits/stdc++.h>
using namespace std;
int main(){
  long long S;
  cin>>S;
  long long N=pow(10,9);
  if (S==pow(10,18)){
      cout<<0<<" "<<0<<" "<<N<<" "<<0<<" "<<0<<" "<<N<<endl;
  }
  else{
    cout<<0<<" "<<0<<" "<<N<<" "<<1<<" "<<N-S%N<<" "<<S/N+1<<endl;
  }
}
