#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int k=0,times[1000] = {0},top,topsoeji,hantei,sizetop,sizetopsoeji,size[1000] = {0};
  char word[1000][32];
  string str;
  while (cin >> str) {
    //cout << str.size();
    for(int i=0;i<str.size();i++) {
      //      word[k][i] = str.substr(i,1);
      word[k][i] = str[i];
      size[k] = str.size();
      if(size[k] > sizetop) {
        sizetop = size[k];
        sizetopsoeji = k;
      }
    }
    //cout << word[k] << endl;
    k++;
  }


  for(int i=0;i<k;i++) {
    for(int j=i+1;j<k;j++) {
      if(strcmp(word[i],word[j]) == 0)
        hantei = 1;
      else
        hantei = 0;
      if(hantei) {
        times[i]++;
        times[j]++;
      }
    }
  }
  //  for(int i=0;i<k;i++)
    //  cout << times[i] << endl;

  top = times[0];
  topsoeji = 0;
  for(int i=0;i<k;i++) {
    if(times[i] > top) {
      top = times[i];
      topsoeji = i;
    }
  }
  cout << word[topsoeji] << " " << word[sizetopsoeji] << endl;

}