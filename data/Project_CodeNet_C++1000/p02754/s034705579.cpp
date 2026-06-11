#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  long long int N;
  long long int A;
  long long int B;
  long long int sum = 0;
  long long int num = 0;
  cin>>N;
  cin>>A;
  cin>>B;
  num = N % (A + B);
  sum += ((N / (A + B)) * A) + (min(num,A));
  cout<<sum<<'\n';
}
