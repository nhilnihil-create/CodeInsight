#include <iostream>
#include <vector>

using namespace std;

int main(){
  int a,b,c,t,g=0,r;
  vector<int> d;
  while(cin >> a >> b >> c,a){
    d.clear();g=0;
    for(int i=0;i<a;i++){
      cin >> t;
      d.push_back(t);
    }r=b;
    //for(int i=0;i<a;i++)cout << d[i] << endl;
    for(int i=b;i<=c;i++){
      // cout << d[i-1] << " " << d[i] << (d[i-1]-d[i]>=g) << endl;
      if((d[i-1]-d[i])>=g){
        g=d[i-1]-d[i];
        r=i;
      }
    }
    cout << r << endl;
  }
}