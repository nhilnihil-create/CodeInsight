#include <iostream>
#include <vector>
using namespace std;


int main(){
  long long N,a;
  cin >> N;
  vector<long long> A(N);
  long long sum=0;
  int sign=1;
  for (int i=0;i<N;++i){
    cin >> a;
    A[i]=a;
    sum+=sign*(a);
    sign*=-1;
  }

  cout << sum << " ";
  for(auto itr=A.begin()+1;itr<A.end();++itr){
    sum=*(itr-1)*2-sum;
    cout << sum << " ";
  }
  cout << endl;
}