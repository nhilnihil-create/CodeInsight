#include<bits/stdc++.h>
using namespace std;

int main() {

  int data[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int month, day;
  while( cin >> month >> day, month + day ) {
    int sum = 0;
    for(int i=0; i<month-1; i++) {
      sum += data[i];
    }
    sum += day;
    sum %= 7;

    if( sum == 1 ) {
      cout << "Thursday" << endl;
    }
    else if( sum == 2 ) {
      cout << "Friday" << endl;
    }
    else if( sum == 3 ) {
      cout << "Saturday" << endl;
    }
    else if( sum == 4 ) {
      cout << "Sunday" << endl;
    }
    else if( sum == 5 ) {
      cout << "Monday" << endl;
    }
    else if( sum == 6 ) {
      cout << "Tuesday" << endl;
    }
    else if( sum == 0 ) {
      cout << "Wednesday" << endl;
    }
  }
}