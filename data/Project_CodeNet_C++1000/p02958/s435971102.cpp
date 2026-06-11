#include<bits/stdc++.h>
 using namespace std;
 int main() {
     int num,counter=0;
     cin >> num;
     vector<int> arr(num);

    for(int f = 0; f <num; f++)
     {
         cin >> arr[f];
     }
     for(int f = 0; f <num; f++)
     {
          if(arr[f] != f + 1)
          counter++;
     }
      if(counter <= 2)
      {
            cout << "YES" << endl;
      }

       else
       {
            cout << "NO" << endl;
       }


    return 0;
}
