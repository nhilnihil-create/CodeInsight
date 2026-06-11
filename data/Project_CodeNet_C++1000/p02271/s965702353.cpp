#include <iostream>

using namespace std;

int n,A[20],s[20],b[10000000],bc=0,q,m;

bool rec(int i){
  if (i == n){
    int sum=0; 
    for(int j=0; j<n; ++j){
      //cout << s[j] << ",";
      if(s[j]) sum += A[j]; 
    }
    b[bc] = sum;
    ++bc;
    //cout << endl;
    return 0;
  }

  rec(i + 1);
  s[i] = 1;
  rec(i + 1);
  s[i] = 0 ;
}

void combi(){
  for(int i=0; i<n; ++i) ;
  rec(0);
}

bool judge(int in){
  for(int i=0; i<bc; ++i)
    if(in == b[i])
      return true;
  return false;
}


int main(){

  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> A[i];
  }

  combi();

  cin >> q;
  for(int i=0; i<q; ++i){
    cin >> m;
    if(judge(m))
      cout << "yes";
    else
      cout << "no";
    cout << endl;
  }
  
  

  return 0;
}

