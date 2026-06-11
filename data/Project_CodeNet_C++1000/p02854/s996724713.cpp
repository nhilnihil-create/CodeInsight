#include <bits/stdc++.h>
using namespace std;
 


int main() {
 
  int64_t n;
  cin>>n;

  vector<int64_t> a(n);
  int64_t sum=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    sum+=a.at(i);
  }

  int64_t half = sum/2;

  int64_t left_sum=0;
  for(int i=0;i<n;i++){
    left_sum+=a.at(i);
    if(left_sum>=half)
        break;
    }

  int64_t right_sum = sum-left_sum;
  int64_t out1 = abs(right_sum-half)+abs(left_sum-half);

  right_sum=0;
  for(int i=n-1;i>=0;i--){
    right_sum+=a.at(i);
    if(right_sum>=half)
        break;
    }

  left_sum=sum-right_sum;
  int64_t out2 = abs(right_sum-half)+abs(left_sum-half);


  cout<<min(out1,out2)<<endl;


	return 0;
}

