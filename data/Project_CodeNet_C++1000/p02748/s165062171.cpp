#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int a,b,m;
  cin >> a >> b >> m;
  vector<int> ref(a);
  vector<int> mic(b);
  for(int i=0; i<a; i++){
    cin >> ref[i];
  }
  for(int i=0; i<b; i++){
    cin >> mic[i];
  }
  
  int pr=0;
  int minref=1e6;
  int minmic=1e6;
  
  for(int i=0; i<a; i++){
    if(ref[i] < minref){
      minref = ref[i];
    }
  }
  for(int i=0; i<b; i++){
    if(mic[i] < minmic){
      minmic = mic[i];
    }
  }
  
  pr = minref + minmic;
  
  int x,y,c;
  
  for(int i=1; i<=m; i++){
    cin >> x >> y >> c;
    if(ref[x-1] + mic[y-1] - c <= pr){
      pr = ref[x-1] + mic[y-1] - c;
    }
  }
  
  cout << pr << endl;
  
	return 0;
}
