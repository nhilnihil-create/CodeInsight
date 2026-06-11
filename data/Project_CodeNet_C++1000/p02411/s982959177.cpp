#include<iostream>
#include<cmath>

using namespace std;

int main(){

int middle_ex=0,last_ex=0,re_ex=0;
int total=0;

while(1){
  cin >> middle_ex >> last_ex >> re_ex;

  total = middle_ex + last_ex;


  if(middle_ex==-1 && last_ex==-1 && re_ex==-1)  break;

  if(total>= 80){
        cout << 'A' << endl;
  }
  else if(middle_ex==-1 || last_ex==-1){
      cout << 'F' << endl;
  }

  else if(65 <= total && total < 80){
        cout << 'B' << endl;
  }
  else if(50 <= total && total < 65){
      cout << 'C' << endl;
  }
  else if(30 <= total && total < 50 && re_ex >= 50){

      cout << 'C' << endl;
  }
  else if(30 <= total && total < 50){

      cout << 'D' << endl;
  }

  else if(total <30){
      cout << 'F' << endl;
  }
re_ex=0;
}

return 0;

}