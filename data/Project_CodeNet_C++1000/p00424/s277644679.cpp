#include <iostream>

using namespace std;

main(){
  int n;
  while(1){
    cin >> n;
    if(n==0) break;

    int data[130];
    for(int i=0;i<130;i++){
      data[i]=i;
    }
    for(int i=0;i<n;i++){
      char a, b;
      cin >> a >> b;
      data[(int)a]=(int)b;
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
      char in;
      cin >> in;
      cout << (char)data[(int)in];
    }
    cout << endl;
  }
  return 0;
}