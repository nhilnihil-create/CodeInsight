#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#define ll long long
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define loop(i,start, stop) for(int i = start; i < (stop); i++)
using namespace std;

int main(){

  ll N;
  cin >> N;
  ll A[200001] = {0};
  ll ans[200001] = {0};
  loop(i,0,N){
    cin >> A[i];
    ans[A[i]]++;
  }

  loop(i,1,N+1)
    cout << ans[i] << endl;

  return 0;
}