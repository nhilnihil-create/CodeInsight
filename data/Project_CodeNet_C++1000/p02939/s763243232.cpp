#include <iostream>
#include <string>

using namespace std;

string s;

//返り値が０でないならOK
int check(string buf,string &next,int i){
   if (buf != next){
     
  //    cout << "OKです　buf: " << buf << " next: " << next << " i: " << i << endl;
      return i;
   }

   i++;
   if (i > s.size()-1){
      next = s.at(i-1);
      if(buf==next)
         return 0;
      else
         return i;
   }

   next += s.at(i);
//   printf("次の文字に進みます i: [%d]\n", i);
   return check(buf, next, i);
}

int main(void){

   
   cin >> s;

   int n = s.size();

   string buf;
   buf = s.at(0);

   int i = 1;
   int cnt = 1;

   while (i < n){
     
      string next;
      next = s.at(i);
      
      //前回と違う文字列の場合
      int move = check(buf, next, i);
      
      if(move == 0)
         break;

      cnt++;

      if (move == i)
         i++;
      else
         i = move+1;

      buf = next;
   }
   cout << cnt << endl;

   return 0;
}