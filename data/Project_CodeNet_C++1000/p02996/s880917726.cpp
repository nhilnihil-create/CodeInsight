#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool compare_by_b(pair<long long, long long>a, pair<long long, long long>b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main(){
  int N;  cin >> N;
  vector<pair<long long,long long> >task(N);
  for(int i=0;i<N;i++){
    cin >> task.at(i).first >> task.at(i).second;
  }

  long long time = 0;
  sort(task.begin(),task.end(),compare_by_b);

  for(int i=0;i<N;i++){
    time += task.at(i).first;
    if(time > task.at(i).second){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
