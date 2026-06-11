#include <iostream>
#include <cstring>

using namespace std;
char dic[256];

int main(void){
  int n;
  cin >> n;
  while(n){
    memset(dic,0,sizeof(dic));

    for(int i=0; i<n; i++){
      char to;
      char from;
      cin >> from >> to;
      dic[from] = to;
    }

    int m; cin >> m;
    
    for(int i=0; i<m; i++){
      char from; cin >> from;
      if(dic[from] == 0)
	cout << from;
      else
	cout << dic[from];
    }
    cout << endl;
    cin >> n;
  }
  return 0;
}