#include<bits/stdc++.h>
using namespace std;

int main(){
  int tree,taisho;
  int kekka;
  cin >> tree >> taisho;
  
  kekka = tree / (taisho * 2 + 1);
  if(tree > kekka * (taisho * 2 + 1)) kekka++;
  
  cout << kekka;
}
