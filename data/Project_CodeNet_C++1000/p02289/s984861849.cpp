#include <iostream>
#include <queue>

using namespace std;

int main(){
  priority_queue<int> PQ;
  char com[20];

  while(1){
    cin>>com;
    if(com[0]=='i'){
      int key;
      cin>>key;
      PQ.push(key);
    }
    else if(com[1]=='x'){
      cout<<PQ.top()<<"\n";
      PQ.pop();
    }

    else{
      break;
    }
  }


  return 0;
}