#include<iostream>
#include<map>
using namespace std;

int main(){
  string S; cin >> S;
  map<char,int>mp;
  for(int i=0;i<S.size();i++){
    mp[S.at(i)]++;
  }
  for(auto itr = mp.begin();itr != mp.end();itr++){
    if(itr->second != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
