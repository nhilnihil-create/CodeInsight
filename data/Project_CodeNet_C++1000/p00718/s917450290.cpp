#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> P;

int n = 0;

int encode(string a){
  vector<int> l;
  for(int i = 0; i < a.size(); i++){
    switch(a[i]){
    case 'm':
      l.push_back(1000);
      break;
    case 'c':
      l.push_back(100);
      break;
    case 'x':
      l.push_back(10);
      break;
    case 'i':
      l.push_back(1);
      break;
    default :
      l.push_back(int(a[i] - '0'));
      break;      
    } 
  }

  int i = 0;
  int sum = 0;
  while(1){
    bool flag = false;
    if(i == l.size()) break;
    if(2 <= l[i] && l[i] <= 9){
      sum += l[i] * l[i + 1];
      flag = true;
    }
    else{
      sum += l[i];
    }

    if(flag){
      i += 2;
    }
    else i++;
  }
  
  return sum;
}

int keisu(int a){
  if(2 <= a && a <= 9) return 1;
  else if(a == 1) return 2;
  return 0;
}

vector<char> decode(int a){
  int m = a / 1000;
  int c = (a % 1000) / 100;
  int x = ((a % 1000) % 100) / 10;
  int i = ((a % 1000) % 100) % 10;

  vector<P> tmp;
  tmp.push_back(P(m, 'm'));
  tmp.push_back(P(c, 'c'));
  tmp.push_back(P(x, 'x'));
  tmp.push_back(P(i, 'i'));

  vector<char> res;
  for(int i = 0; i < 4; i++){
    if(keisu(tmp[i].first) == 1){
      res.push_back(char(tmp[i].first + '0'));
      res.push_back(tmp[i].second);
    }
    else if(keisu(tmp[i].first) == 2){
      res.push_back(tmp[i].second);
    }
  }
  return res;
}

void display(vector<char> res){
  for(int i = 0; i < res.size(); i++){
    cout << res[i];
  }
  cout << endl;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    string a, b;
    cin >> a >> b;
    int sum = encode(a) + encode(b);
    vector<char> res = decode(sum);
    display(res);
  }
  
  return 0;
}