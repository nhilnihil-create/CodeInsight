#include <iostream>
#include <vector>
using namespace std;

int main(){
  int m, f, r;
  vector<int> t, k, s;
  while(true){
    cin >> m >> f >> r;
    if(m==-1 && f==-1 && r==-1) break;

    t.push_back(m); k.push_back(f); s.push_back(r);
  }

  for(int i=0; i<(int)t.size(); i++){
    char res;
    if(t[i]==-1 || k[i]==-1) res='F';
    else if(t[i]+k[i]>=80) res='A';
    else if(t[i]+k[i]>=65 && t[i]+k[i]<80) res='B';
    else if(t[i]+k[i]>=50 && t[i]+k[i]<65) res='C';
    else if(t[i]+k[i]>=30 && t[i]+k[i]<50){
      if(s[i]>=50) res='C';
      else res='D';
    }
    else res='F';

    cout << res << endl;
  }

  return 0;
}

