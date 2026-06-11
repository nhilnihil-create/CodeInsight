#include <iostream>
using namespace std;

int n, a, b, c = 0;
bool f = 0;

int main(){

cin >> n;

for(int i = 0; i < n; i++){
    cin >> a >> b;

    if(a == b)
      c++;
    else
      c = 0;

    if(c > 2)
    f = 1;
}

if(f)
  cout << "Yes" << endl;
else
  cout << "No" << endl;
}
