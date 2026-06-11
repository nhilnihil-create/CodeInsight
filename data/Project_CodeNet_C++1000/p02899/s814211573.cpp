#include <iostream>
#include <algorithm>

using namespace std;

struct stu{
  int tim, per;
};

bool compare(stu a, stu b){
  if(a.tim < b.tim){
    return true;
  }else{
    return false;
  }
}

int const nmax =1e5;
stu late[1 + nmax];

int main() {

  int n;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> late[i].tim;
    late[i].per = i;
  }
  sort(late+1, late+n+1, compare);
  for(int i = 1;i <= n;i++){
    cout << late[i].per << ' ';
  }
  return 0;
}
