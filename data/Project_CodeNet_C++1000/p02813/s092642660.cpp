#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int>P(n);
  vector<int>Q(n);
  for(int i=0;i<n;i++){
    cin >> P.at(i);
  }
  for(int i=0;i<n;i++){
    cin >> Q.at(i);
  }
  vector<int>A(n);
  for(int i=0;i<n;i++){
    A.at(i) = i + 1;
  }

  int pe,qe;
  int jun = 1;
  do{
    int p = 0;
    int q = 0;
    for(int i=0;i<n;i++){
      if(A.at(i) == P.at(i))  p++;
      if(A.at(i) == Q.at(i))  q++;
    }
    if(p == n)  pe = jun;
    if(q == n)  qe = jun;
    jun++;
  }while(next_permutation(A.begin(),A.end()));
  if(pe - qe >= 0) cout << pe - qe << endl;
  else  cout << qe - pe << endl;
}
