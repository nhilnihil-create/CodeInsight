#include<bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0;i <n; i++)
    cin>>arr[i];
 
  map<int,int> counts;
  
  /********sieve*************/
  vector<int> min_prime(N+1,0);
  for(int i = 2; i * i <= N;i++) {
    if(min_prime[i] == 0) {
      for(int j = i * i; j <= N; j+=i) {
        if(min_prime[j] == 0)
          min_prime[j] = i;
      }
    }
  }
  for(int i = 2; i <= N;i++) {
    if(min_prime[i] == 0) {
      min_prime[i] = i;
    }
  }
  /*****sieving ends*****/
  
  bool pairwise_coprime = true;
  bool setwise_coprime = true;
  for(int i =0;i < n;i++) {
    set<int> factors;
    while(arr[i] != 1) {
      factors.insert(min_prime[arr[i]]);
      arr[i] = arr[i] / min_prime[arr[i]];
    }
    for(auto it = factors.begin();it != factors.end();it++) {
      counts[*it]++;
    }
  }
  
  for(auto it = counts.begin(); it!= counts.end(); it++) {
    //cout<<it->first<<" "<<it->second<<endl;
   	if(it->second == n)
      setwise_coprime = false;
    if(it->second > 1)
      pairwise_coprime = false;
  }
  if(!pairwise_coprime) {
    if(setwise_coprime)
        cout<<"setwise coprime\n";
    else
    	cout<<"not coprime\n";
  } else {
    cout<<"pairwise coprime\n";
  }
  return 0;
}