

   #include <bits/stdc++.h>
   using namespace std;
   int main()
   {
      //    string in;
      //  getline(cin,in);
      //  cout<<in;
      //  int t;
      //  cin >> t;
      //  while (t--)
      //  {
         long long num;
         string str;
         cin >> num;

         char temp;
         while (num > 0)
         {
               temp = num % 26;
               if (temp == 0)
               {
                  if (num / 26 != 0)
                  {
                     str.push_back('z');
                     num--;
                  }
               }
               else
               {
                  temp = temp + 96;
                  str.push_back(temp);
                  //cout<<temp;
               }
               temp = 0;
               num /= 26;
         }

         reverse(str.begin(), str.end());
         cout << str << endl;
         
      //  }
   }