#include <iostream>
#include <algorithm>


using namespace std;

int main()
{

    int N,X,in,position,flag=0;
    cin >> N >> X;

    position = 0;
    if(position <= X){
        flag++;
        }
        while(N--){
          cin >> in;
          position += in;
          if(position <= X){
            flag++;
          }else {
            break;
          }
        }
        cout << flag << endl;


    }
