#include <bits/stdc++.h>
typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
  int n;
  cin>>n;
  vector <pair<int,int>> tasks;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    tasks.emplace_back(b,a); // 締め切り、所要時間
  }

  sort(tasks.begin(), tasks.end()); 
  int sum = 0;
  bool isyes= 1;
  for(auto v: tasks){
    sum += v.second; //aの所要時間をsumに足していく
    if(sum > v.first){//sumが締め切りより大きいならば
      isyes = 0;//締め切りに間に合わないのでNo(false)にする
      break;
    }
  }
  cout << (isyes ? "Yes": "No") << endl;
  return 0;
}