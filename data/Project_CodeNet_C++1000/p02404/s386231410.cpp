#include <iostream>
using namespace std;

int main() {
  int h,w;

  scanf("%d %d",&h,&w);
  while( h!=0 || w!=0) {
      cout << string(w,'#') << endl;

      for(int i=1;i<h-1;i++)
      {
          cout << "#" + string(w-2,'.') + "#" << endl;
      }

      if(h>1) {
          cout << string(w,'#') << endl;
      }
      cout << endl;
      scanf("%d %d",&h,&w);
  }

  return 0;
}