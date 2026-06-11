#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, boi;
  //string popo, team, huff= "Hufflepuff:\n", rave = "Ravenclaw:\n", slyt = "Slytherin:\n", gryf = "Gryffindor:\n";
  cin >> n;
  boi = n;
  cin >> n;
  boi += n;
  cin >> n;
  boi += n;
  if(boi > 21){
    cout << "bust";
  }else{
    cout << "win";
  }
  return 0;
}
