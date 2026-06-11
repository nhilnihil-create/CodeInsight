#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> vec(N, 0);
  for(int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  int ans=0;
  sort(vec.begin(), vec.end());
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      if(vec.at(i)==vec.at(j)){
        continue;
      }
      for(int k=j+1; k<N; k++){
        if(vec.at(j)==vec.at(k)||vec.at(i)==vec.at(k)){
        continue;
        }
        if(vec.at(i)+vec.at(j)>vec.at(k)){
         // cout<<vec.at(i)<<vec.at(j)<<vec.at(k)<<endl;
          ans++;
        }
      }
    }
  }
 cout<<ans<<endl;
}