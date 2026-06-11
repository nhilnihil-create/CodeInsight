#include <iostream>
using namespace std;

int main(){
  char c[101];
  while(cin.getline(c, sizeof(c))&&c[0]!='.'){
    char a[101];
    int j=0;
    for(int i=0;i<102;i++){
      if(c[i]=='('||c[i]==')'||c[i]=='['||c[i]==']'){
        a[j]=c[i];
        if((a[j-1]=='('&&a[j]==')')||(a[j-1]=='['&&a[j]==']')){
          a[j-1] = '\0';
          a[j] = '\0';
          j--;
        }else{
          j++;
        }
      }
    }

    //  cout << a << endl;
    if(j==0) cout << "yes" << endl;
    else cout << "no" << endl;
    // initialize
    for(int i=0;i<102;i++){
      a[i] = '\0';
      c[i] = '\0';
    }
  }

  return 0;
}