#include<iostream>
#include<vector>
#include<tuple>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int>jun(n);
  vector<vector<double> >dis(n,vector<double>(n));
  vector<pair<int,int> >z;
  for(int i=0;i<n;i++){
    jun.at(i) = i;
    int x,y;  cin >> x >> y;
    z.push_back(make_pair(x,y));
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      dis.at(i).at(j) = sqrt((z.at(i).first - z.at(j).first)*(z.at(i).first - z.at(j).first) + (z.at(i).second - z.at(j).second)*(z.at(i).second - z.at(j).second));
      dis.at(j).at(i) = dis.at(i).at(j);
    }
  }

  long double sum = 0;
  int count = 0;
  do{
    for(int i=0;i<n-1;i++){
      sum += dis.at(jun.at(i)).at(jun.at(i+1));
    }
    count++;
  }while(next_permutation(jun.begin(),jun.end()));

  cout << fixed << setprecision(10) << sum/count << endl;
}
