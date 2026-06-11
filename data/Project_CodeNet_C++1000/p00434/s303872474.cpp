#include <iostream>
#include <map>

using namespace std;

main(){
  int in;
  while(cin >> in){
    map<int, bool> student;
    student[in]=true;
    for(int i=0;i<27;i++){
      cin >> in;
      student[in]=true;
    }
    for(int i=1;i<=30;i++){
      if(!student[i]) cout << i << endl;
    }
  }
  return 0;
}