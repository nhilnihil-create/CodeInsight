#include <vector>
#include <iostream>
#include <map>
#include <string>

using namespace std;
int main(){
  long long int n; cin >> n;
  map<long long int, long long int> cnt;
  for(int i=0;i<n;i++){
    long long int a; cin >> a;
    cnt[a]++;
  }
  auto itr =cnt.begin();
  auto itr1=cnt.begin(); itr1++;
  auto itr2=cnt.begin(); itr2++; itr2++;

  string ans;
  if(cnt.size()==1) ans=(itr->first==0) ? "Yes":"No";
  else if(cnt.size()==2){
    if(itr->first==0) ans=(itr->second*2==itr1->second) ? "Yes":"No";
    // else if(itr1->first==0) ans=((itr->second)==itr1->second*2) ? "Yes":"No";
	else ans="No";
  }
  else if(cnt.size()==3){
    if(itr->second==itr1->second 
       && itr1->second==itr2->second){
      ans=((itr->first^itr1->first)==itr2->first) ? "Yes":"No";
    }
    else ans="No";
  }
  else ans="No";
  cout << ans << endl;
  return 0;
}
