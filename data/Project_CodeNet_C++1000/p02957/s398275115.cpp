#include <bits/stdc++.h>
 using namespace std;
 int main() {
     int firstIn, secondIn,value,temp1,temp2;
     cin >> firstIn>> secondIn;
     temp1=firstIn%2;
     temp2=secondIn%2;

      if(temp1!=temp2)
        cout << "IMPOSSIBLE" << endl;
      else
      {
          value= (firstIn + secondIn) / 2;
          cout <<value<< endl;
      }

     return 0;
}
