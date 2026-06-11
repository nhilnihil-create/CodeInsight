#include <iostream>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  string s, max("");
  map<string, int> w; // stringÅsort³êé
  map<int, string, greater<int> > x; // int Åsort³êé = ÅÌÆ±ÉÅåo»ñ

  while(cin >> s){
    //Åå·Ì¶ðXV
    if(s.size() > max.size()) max = s;
    w[s]++;
  }
  
  for(map<string, int>::iterator it = w.begin() ; it != w.end() ; it++){
    x[(*it).second] = (*it).first;
    //cout << "first = " << (*it).first << ", second =  " << (*it).second << endl;
  }

  /*for(map<int, string>::iterator it = x.begin() ; it != x.end() ; it++){
    x[(*it).second] = (*it).first;
    cout << "first = " << (*it).first << ", second =  " << (*it).second << endl;
  }*/
  
  cout << (*x.begin()).second << " " << max << endl;
  return 0;
}