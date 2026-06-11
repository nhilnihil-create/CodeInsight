#include <iostream>
#include <string>

using namespace std;

int func(char w)
{
  char n = '0';
  for(int i = 2; i <= 10; i++){
    if(w == (char)(n+i)){
      return i;
    }
  }

  return 1;
}

int main()
{
  int n, s, t, v;
  string s1, s2;
  char w = '0';
  cin >> n;
  while(n--){
    cin >> s1 >> s2;
    s = t = 0;

    for(int i = 0; i < s1.size(); i++){
      v = func(s1[i]);
      if(v > 1){
	i++;
      }
      if(s1[i] == 'm'){
	s += v*1000;
      } else if(s1[i] == 'c'){
	s += v*100;
      } else if(s1[i] == 'x'){
	s += v*10;
      } else if(s1[i] == 'i'){
	s += v;
      }
    }

    for(int i = 0; i < s2.size(); i++){
      v = func(s2[i]);
      if(v > 1){
	i++;
      }
      if(s2[i] == 'm'){
	t += v*1000;
      } else if(s2[i] == 'c'){
	t += v*100;
      } else if(s2[i] == 'x'){
	t += v*10;
      } else if(s2[i] == 'i'){
	t += v;
      }
    }
    s += t;
    s1 = "";

    v = s/1000;
    if(v > 0){;
      if(v > 1){
	s1 += (char)(w+v);
      }
      s1 += 'm';
      s -= v*1000;
    }
    v = s/100;
    if(v > 0){
      if(v > 1){
	s1 += (char)(w+v);
      }      
      s1 += 'c';
      s -= v*100;
    }
    v = s/10;
    if(v > 0){
      if(v > 1){
	s1 += (char)(w+v);
      }
      s1 += 'x';
      s -= v*10;
    }
    if(s > 0){
      if(s > 1){
	s1 += (char)(w+s);
      }
      s1 += 'i';
    }

    cout << s1 << endl;
  }

  return 0;
}