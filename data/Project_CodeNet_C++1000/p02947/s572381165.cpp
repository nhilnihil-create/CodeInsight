#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<string>a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
    sort(a.at(i).begin(),a.at(i).end());
  }
  sort(a.begin(),a.end());
  long long cnt=0,count=0;
  string copy=a.at(0);
  for(int i=0;i<n;i++){
    if(a.at(i)==copy){
      count++;
    }
    else{
      cnt+=(count*(count-1))/2;
      count=1;
      copy=a.at(i);
    }
  }
  cnt+=(count*(count-1))/2;
  cout << cnt << endl;
  return 0;
}
