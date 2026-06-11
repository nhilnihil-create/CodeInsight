#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> data;
int n, m;

main(){
  cin >> n;
  for(int i=0;i<n;i++){
    string in;
    cin >> in;
    data.insert(in);
  }
  cin >> m;
  int open = 0;
  for(int i=0;i<m;i++){
    string in;
    cin >> in;
    if(data.find(in) != data.end()){
      cout << (open ? "Closed by" : "Opened by") << ' ' << in << endl;
      open = 1 - open;
    }else cout << "Unknown" << ' ' << in << endl;
  }
}