#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int cnt = 0;

void insertionsort(vector<int> &vec,int gap){
  for(int i=gap;i < vec.size();i++){
    int v = vec.at(i);
    int j = i - gap;
    while(j >= 0 && vec.at(j) > v){
      vec.at(j+gap) = vec.at(j);
      j-=gap;
      cnt++;
    }
    vec.at(j+gap) = v;
  }
}

void shellsort(vector<int> &vec){
  int m = (int)log2((double)vec.size())+1;
  vector<int> G(m);
  int l = vec.size();
  for(int i=0;i < m;i++){
    G.at(i) = l;
    l /= 2;
  }
  for(int i=0;i < m;i++){
    insertionsort(vec,G.at(i));
  }
  cout << m << endl;
  for(int i=0;i < G.size();i++){
    cout << G.at(i);
    if(i != G.size()-1) cout << " ";
    else cout << endl;
  }
  cout << cnt << endl;
  for(int i=0;i < vec.size();i++){
    cout << vec.at(i) << endl;
  }
}

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i=0;i < A.size();i++){
    cin >> A.at(i);
  }
  shellsort(A);

  return 0;
}
