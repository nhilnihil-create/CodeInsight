#include <iostream>
using namespace std;
class Dice {
 public:
  int dice[6];
  int label[6];
  int tmp;
  void init() {
	for(int i = 0; i < 6; ++i) {
	  dice[i] = label[i];
	}
  }
  void moveN() {
	tmp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = tmp;
  }
  void moveS() {
	tmp = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = tmp;
  }
  void moveE() {
	tmp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = tmp;
  }
  void moveW() {
	tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = tmp;
  }
};
/*
void print(Dice d1) {
    for(int i = 0; i < 6; ++i) {
	  cout << "i:" << i << endl;
	  cout << "\tdice:" << d1.dice[i] << endl;
	}
}
*/
int main() {
  Dice d1;
  char ch;
  
  for(int i = 0; i < 6; ++i) {
	cin >> d1.label[i];
  }
  d1.init();

  while(cin >> ch) {
	if(ch == 'N') {
	  d1.moveN();
	}
	else if(ch == 'E') {
	  d1.moveE();
	}
	else if(ch == 'S') {
	  d1.moveS();
	}
	else {
	  d1.moveW();
	}
	//	print(d1);
  }
  cout << d1.dice[0] << endl;

  return 0;
}