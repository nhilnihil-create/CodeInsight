#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> a){
  for(int i=0;i<a.size();i++){
    cout << a[i] << endl;
  }
  cout << endl;
}
int main(){
  while(1){
    int N,R;
    cin >> N >> R;
    if(N==0&&R==0)break;
    vector<int> a;
    for(int i=N;i>=1;i--){
      a.push_back(i);
    }
    for(int i=0;i<R;i++){
      int p,c;
      cin >> p >> c ;
      vector<int> b;
      for(int j=0;j<c;j++){
        b.push_back(a[p-1+j]);
      }
      a.erase(a.begin()+p-1,a.begin()+p-1+c);
      a.insert(a.begin(),b.begin(),b.end());
    }
    cout << a[0] << endl;
  }
}

