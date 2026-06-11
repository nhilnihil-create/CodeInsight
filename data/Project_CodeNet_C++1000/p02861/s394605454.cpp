#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int x[10],y[10];

double dist(int i,int j){
      double dx = x[i] - x[j];
      double dy = y[i] - y[j];
      return sqrt(dx * dx + dy * dy);
}
int main(void){
    cin >> N;
    for(int i = 1;i <= N;i++){
          cin >> x[i] >> y[i];
    }
    vector<int>v(N);
    for(int i = 0;i < N;i++){
          v[i] = i + 1;
    }
    double sum = 0.0;
    do{
          for(int i = 0;i < N - 1;i++){
                sum += dist(v[i],v[i + 1]);
          }
    }while(next_permutation(v.begin(),v.end()));
    int f = 1;
    for(int i = 2;i <= N;i++)f *= i;
    printf("%0.10f\n",sum / f);
}
