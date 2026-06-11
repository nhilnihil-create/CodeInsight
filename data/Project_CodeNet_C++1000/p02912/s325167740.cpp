#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N,tickets;
  cin >> N >> tickets;
  priority_queue<long long> pq;
  froop1(0,N){
    long long a;
    cin >> a;
    pq.push(a);
  }
  froop1(0,tickets){
  	long long b = pq.top();
    pq.pop();
    pq.push(b / 2);
  }
 	long long sum = 0;
  while(!pq.empty()){
    sum += pq.top();
    pq.pop();
  }
  cout << sum << endl;
}