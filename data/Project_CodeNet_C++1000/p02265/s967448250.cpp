#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  deque<int> que;
  for(int i = 0; i < n; i++){
    string  order;
    int value;
    cin >> order;
    if(order == "deleteFirst" || order == "deleteLast"){
      if(order == "deleteFirst") que.pop_front();
      else  que.pop_back();
      continue;
    }
    cin >> value;
    if(order == "insert"){
      que.push_front(value);
    }else{
      for(auto itr = que.begin(); itr != que.end(); ++itr){
        if(*itr == value){
          que.erase(itr);
          break;
        }
      }
    }
  }

  for(auto itr = que.begin(); itr < que.end() - 1; itr++){
    cout << *itr << " ";
  } cout << que.back() << endl;
  return 0;
}