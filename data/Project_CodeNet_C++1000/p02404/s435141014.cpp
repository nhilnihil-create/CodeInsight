#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int a = 0, b = 0, i = 0,j = 0, k =0;
    for(k=0 ;; k++){
        cin >> a >> b;
        if((a==0)||(b==0))break;

        for(i = 0; i < a; i++){
            for(j = 0; j < b; j++){
               if(j==0 || j==b-1 || i==0 | i ==a-1)
               cout << '#';
               else cout<<'.';
            }
            cout << endl;
        }

        cout << endl;
    }

}