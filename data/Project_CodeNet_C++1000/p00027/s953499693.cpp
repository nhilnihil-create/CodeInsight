#include <iostream>

using namespace std;

int main(void){

  int month[13] ={0,31,29,31,30,31,30,31,31,30,31,30,31};
  int m,d;

  while( cin >> m >> d ){
    if( m == d && d == 0 )break;

    int sum = 0;
    for( int i = 1 ; i < m ; i++ ){
      sum += month[i];
    }

    sum += d; 
    sum %= 7;

    switch(sum){
    case 0:
      cout << "Wednesday" << endl;
      break;
    case 1:
      cout << "Thursday" << endl;
      break;
    case 2:
      cout << "Friday" << endl;
      break;
    case 3:
      cout << "Saturday" << endl;
      break;
    case 4:
      cout << "Sunday" << endl;
      break;
    case 5:
      cout << "Monday" << endl;
      break;
    case 6:
      cout << "Tuesday" << endl;
      break;
    }
  }
  return 0;
}