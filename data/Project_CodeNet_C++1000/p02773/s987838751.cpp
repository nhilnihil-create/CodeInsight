#include <iostream>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
    // Your code here!
map<string , int> mp;
int n;
cin>>n;

for(int i=0;i<n;i++){
 string s;
 cin>>s;
 mp[s]++;
}
int minv=1e9, maxv=-1;
for(auto it=mp.begin();it!=mp.end();it++){
    maxv= max(it->second, maxv);
        
}

for (auto p : mp) {
    auto k = p.first;
    auto v = p.second;
    if(v==maxv)
    cout << k << endl;
  }
}

