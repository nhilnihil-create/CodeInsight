#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> data(N,vector<int>(2));
  for(int i=0;i<N;i++){
    cin >> data.at(i).at(0) >> data.at(i).at(1);
  }
  
  vector<int> order(N);
  for(int i=0;i<N;i++){
    order.at(i)=i;
  }
  
  long double sum=0.0;
  double c=0.0;
  
  do{
    for(int i=0;i<N-1;i++){
      int p1,p2;
      p1=order.at(i);
      p2=order.at(i+1);
      sum+=sqrt(pow(data.at(p1).at(0)-data.at(p2).at(0),2)+pow(data.at(p1).at(1)-data.at(p2).at(1),2));
    }
    c+=1.0;
  }while (next_permutation(order.begin(), order.end()));
  cout << fixed << setprecision(7);
  cout << sum/c;
}
