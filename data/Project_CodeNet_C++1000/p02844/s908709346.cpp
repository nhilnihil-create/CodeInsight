#include <iostream>
#include <string>

using namespace std;

int main(){
  int N, ans=0, flg=0;
  string S;
  cin >> N >> S;

  int pos = 0;
  for (int i = 0; i < 10; i++){
    char c = '0' + i;

    pos = S.find(c);

    if (pos == string::npos) continue;
    int jpos = pos;

    for (int j = 0; j < 10; j++){
      char c = '0' + j;


      pos = S.substr(jpos+1).find(c);

      if (pos == string::npos) continue;

      int kpos = pos + jpos + 1;
      for (int k = 0; k < 10; k++){
        char c = '0' + k;

        pos = S.substr(kpos+1).find(c);

        if (pos == string::npos){
          continue;
        }else{
          ans++;
          continue;
        }
        
      }
    }
  }

  printf("%d\n",ans);
  
}
