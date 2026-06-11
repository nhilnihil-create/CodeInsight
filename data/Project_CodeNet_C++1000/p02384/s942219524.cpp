#include<iostream>
#include<string>
#include<math.h>
using namespace std;


struct Dice{
    int f[6];
    void roll(char temp){
        switch (temp)
      {
        int temp_1;
        case 'S':
          temp_1 = f[4];
          f[4] = f[5];
          f[5] = f[1];
          f[1] = f[0];
          f[0] = temp_1;
          break;
        case 'N':
            temp_1 = f[1];
            f[1] = f[5];
            f[5] = f[4];
            f[4] = f[0];
            f[0] = temp_1;
            break;
        case 'W':
            temp_1 = f[2];
            f[2] = f[5];
            f[5] = f[3];
            f[3] = f[0];
            f[0] = temp_1;
            break;
        case 'E':
            temp_1 = f[2];
            f[2] = f[0];
            f[0] = f[3];
            f[3] = f[5];
            f[5] = temp_1;
            break;
        case 'R':
            temp_1=f[1];
            f[1]=f[2];
            f[2]=f[4];
            f[4]=f[3];
            f[3]=temp_1;
            break;
      
        default:
            break;
      }
    }
    int top(){
        return f[0];
    }
    int right(){
        return f[2];
    }
    int left(){
        return f[3];
    }
    int front(){
        return f[1];
    }
};

int main(){
  Dice d;
  for(int i = 0;i<6;i++){
      cin>>d.f[i];
  }
  int n;
  cin>>n;
  while(n--){
    int a,b;
    cin >> a >> b;
    if(d.left()==a) d.roll('E');
    if(d.right()==a) d.roll('W');
    while(d.top()!=a) d.roll('N');
    while(d.front()!=b) d.roll('R');
    cout << d.right() << endl;
  }
  return 0;
}
