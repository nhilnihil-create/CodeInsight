#include<bits/stdc++.h>
using namespace std;

string guki(int a){
  if(a % 2 == 0)return "gu";
  else return "ki";
}

int main(){
  unsigned long long int h,w;
  cin >> h >> w;
  unsigned long long int count = 0;
  
  if(guki(h) == "gu" && guki(w) == "gu"){count = (h / 2) * w;}
  else if(guki(h) == "gu" && guki(w) == "ki"){count = (h / 2) * w;}
  else if(guki(h) == "ki" && guki(w) == "gu"){count = h * (w / 2);}
  else if(guki(h) == "ki" && guki(w) == "ki"){count = ((h * w) / 2) + 1;}
  
  if(h == 1 || w == 1)count = 1;
  cout << count << endl;
}