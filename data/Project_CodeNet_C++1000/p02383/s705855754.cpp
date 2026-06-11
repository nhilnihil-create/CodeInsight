#include<iostream>
#include<vector>

using namespace std;

class Dice{
private:
  int value[6];
  int status[6]; //0:top,1:front,2:right,3:left,4:back,5:bottom
public:
  Dice(int*);
  void rotate(char);
  void show_value();
  void show_status();
  int show_top();
};

int main(int argc, char const *argv[]) {

  int dice_value[6];

  for(int i=0;i<6;i++){
    cin >> dice_value[i];
  }

  char direction[100];

  for(int i=0;i<100;i++){
    cin >> direction[i];
  }

  Dice dice(dice_value);

  //dice.show_value();
  //dice.show_status();

  for(int i=0;i<100;i++){
    dice.rotate(direction[i]);
  }

  dice.show_top();

  return 0;
}

Dice::Dice(int* input){
  for(int i=0;i<6;i++){
    value[i]=input[i];
    status[i]=i;
  }
}

void Dice::show_value(){
  for(int i=0;i<6;i++){
    cout << value[i] << " ";
  }
  cout << endl;
}

void Dice::show_status(){
  for(int i=0;i<6;i++){
    cout << status[i] << " ";
  }
  cout << endl;
}

void Dice::rotate(char direct){
  //index of status[i]---0:top,1:front,2:right,3:left,4:back,5:bottom
  int before_status[6];
  for(int i=0;i<6;i++){
    before_status[i]=status[i];
  }

  switch(direct){
    case 'E':
    status[2] = before_status[0];
    status[5] = before_status[2];
    status[0] = before_status[3];
    status[3] = before_status[5];
    break;
    case 'W':
    status[3] = before_status[0];
    status[0] = before_status[2];
    status[5] = before_status[3];
    status[2] = before_status[5];
    break;
    case 'N':
    status[4]=before_status[0];
    status[0]=before_status[1];
    status[5]=before_status[4];
    status[1]=before_status[5];
    break;
    case 'S':
    status[1]=before_status[0];
    status[5]=before_status[1];
    status[0]=before_status[4];
    status[4]=before_status[5];
    break;
    default:
    break;
  }

}

int Dice::show_top(){
  cout << value[status[0]] << endl;
}