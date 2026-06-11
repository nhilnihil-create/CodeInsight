#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)

#define ll long long

#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));

int main(){
	long long N,B,R;
  cin >> N >> B >> R;
  long long count = N / (B + R);
  N %= (B + R);
  long long b;
  if(N >= B){
    b = B;
  }else{
    b = N;
  }
  cout << count*B + b << endl;
}