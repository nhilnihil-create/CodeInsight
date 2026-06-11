#include<iostream>
#include<cstdio>
using namespace std;

class Dice_c{

private:
  int me[4];
  int topbot[2]; // top,bottom

public:
  void Input();
  void Roll(int top, int front);
  void Output();

};


int main(){

  Dice_c dice;
  int m;
  int top,front;

  dice.Input();
  cin >> m;

  for(int i=0; i<m; i++){
    cin >> top >> front;
    dice.Roll(top,front);
    dice.Output();
  }

  
  return 0;
}


///////////////////////////////////////




void Dice_c::Input(){

  cin >> me[1] >> topbot[1] >> me[2] >> me[0] >> topbot[0] >> me[3];
  getchar();

}

void Dice_c::Roll(int top,int front){
  
  int tmp;

  if(me[1]!=top){


    if(me[0]==top){
      tmp=me[3];
      me[3]=me[2] , me[2]=me[1] , me[1]=me[0] , me[0]=tmp;
    }
    else if(me[2]==top){
      tmp=me[0];
      me[0]=me[1] , me[1]=me[2] , me[2]=me[3] , me[3]=tmp;
    }
    else{
      while(me[1]!=top){
	tmp = topbot[0];
	topbot[0]=me[1] , me[1]=topbot[1] , topbot[1]=me[3] , me[3]=tmp;
	
	/*
	cout << endl << "top:" <<top << endl;

	cout <<endl <<  "  " << topbot[0] << endl;
	for(int i=0; i<4; i++)
	  cout << me[i] << ' ';
	cout << endl << "  " << topbot[1] << endl;
	*/


      }
    }
  }
  ///////fix top

  while(topbot[1]!=front){
    tmp=topbot[1];
    topbot[1]=me[2] , me[2]=topbot[0] , topbot[0]=me[0] , me[0]=tmp;

  }
  ///////fix front
 

}


void Dice_c::Output(){

  cout << me[2] << endl;

}