#include <iostream>
#include <string>

#define MAX_LEN (100)

using namespace std;

int all_diff(int value[]);

class Dice {
      private:
              int value[6];
              int top;
     
      public:             
              Dice(int value[]) {             
                   for (int i = 0; i < 6; i++) {
                        this->value[i] = value[i];
                   }
                   
                   this->top = value[0];
              }
                                           
              int Get_right(int top, int front) {
                  if (top == this->value[0]) {
                      if (front == this->value[1]) {
                          return (this->value[2]);
                      } else if (front == this->value[2]) {
                          return (this->value[4]);
                      } else if (front == this->value[3]) {
                          return (this->value[1]);
                      } else if (front == this->value[4]) {
                          return (this->value[3]);
                      }
                  } else if (top == this->value[1]) {
                      if (front == this->value[0]) {
                          return (this->value[3]);
                      } else if (front == this->value[2]) {
                           return (this->value[0]);
                      } else if (front == this->value[3]) {
                           return (this->value[5]);
                      } else if (front == this->value[5]) {
                           return (this->value[2]);
                      }
                  } else if (top == this->value[2]) {
                      if (front == this->value[0]) {
                          return (this->value[1]);
                      } else if (front == this->value[1]) {
                          return (this->value[5]);
                      } else if (front == this->value[4]) {
                          return (this->value[0]);
                      } else if (front == this->value[5]) {
                          return (this->value[4]);
                      }
                  } else if (top == this->value[3]) {
                      if (front == this->value[0]) {
                          return (this->value[4]);
                      } else if (front == this->value[1]) {
                          return (this->value[0]);
                      } else if (front == this->value[4]) {
                          return (this->value[5]);
                      } else if (front == this->value[5]) {
                          return (this->value[1]);
                      }
                  } else if (top == this->value[4]) {
                      if (front == this->value[0]) {
                          return (this->value[2]);
                      } else if (front == this->value[2]) {
                          return (this->value[5]);
                      } else if (front == this->value[3]) {
                          return (this->value[0]);
                      } else if (front == this->value[5]) {
                          return (this->value[3]);
                      }
                  } else if (top == this->value[5]) {
                      if (front == this->value[1]) {
                          return (this->value[3]);
                      } else if (front == this->value[2]) {
                          return (this->value[1]);
                      } else if (front == this->value[3]) {
                          return (this->value[4]);
                      } else if (front == this->value[4]) {
                          return (this->value[2]);
                      }
                  }
              }
 };

int main()
{
    int value[6];  
    int q;   
       
    do {
        for (int i = 0; i < 6; i++) {
             do {
                 cin >> value[i];
             } while (value[i] < 0 || value[i] > 100);
        }
    } while (all_diff(value) == 0);    

    Dice dice(value);

    do {
        cin >> q;
    } while (q < 1 || q > 24);

    int* top = new int[q];
    int* front = new int[q];
  
    for (int i = 0; i < q; i++) {
         do {
             cin >> top[i] >> front[i];
         } while ((top[i] < 0 || top[i] > 100) || (front[i] < 0 || front[i] > 100));
    }
   
    for (int i = 0; i < q; i++) {
         cout << dice.Get_right(top[i], front[i]) << endl;
    }

    delete[] top;
    delete[] front; 
 
    return (0);
}

int all_diff(int value[])
{
    int i;
    int flag[MAX_LEN] = {0};

    for (i = 0; i < 6; i++) {
         if (i >= 1) {
             if (flag[value[i] - 1] == 1) {
                 break;
             }
         }

         flag[value[i] - 1] = 1;  
    }

    if (i == 6) {
        return (1);
    } else {
        return (0);
    }
}