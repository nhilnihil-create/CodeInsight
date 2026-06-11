#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int count=0;

    int n,x,input;

    cin >> n >> x;
    int pos = 0;
    if(pos <= x){
      count++;
    }
    while(n--){
      cin >> input;
      pos += input;
      if(pos <= x){
        count++;
      }else {
        break;
      }
    }
    cout << count << endl;

    return 0;
}
