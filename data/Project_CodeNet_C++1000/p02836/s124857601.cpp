#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;

    if(s.size() % 2 == 0){
        int middle = s.size() / 2 ;
        int end = s.size() - 1;
        int matchEvenCount = 0;
        for (int i = 0; i < middle; i++)
        {
            if (s[i] != s[end - i])
            {
                matchEvenCount++;
            }
        }

        cout << matchEvenCount << endl;
    }
    else if(s.size() % 2 != 0){
        int middle = s.size()/ 2 + 1;
        int end = s.size() -1;
        int matchOddCount = 0;
         for (int i = 0; i < middle ; i++)
        {
            if(s[i] != s[end -i]){
                matchOddCount++;
            }
        }

        cout << matchOddCount << endl;
        
    }

  
  return 0;
}