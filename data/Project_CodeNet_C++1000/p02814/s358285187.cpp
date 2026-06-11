#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}
long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}
int main()
{
  long long n, m, ans = 0;
  cin >> n >> m;
  vector<long long> a(n);
  for(int i=0;i<n;i++){
  	cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  long long l = a[0];
  int cnt = 0;
  while(l%2 == 0){
  	l /= 2;
  	cnt++;
  }
  
  bool flag = 1;
  long long tw = pow(2, cnt);
  long long x = tw/2;
  
  for(int i=0;i<n;i++){
  	if(a[i]%tw == 0){
  		if(a[i]%(2*tw)==0){
  			ans = 0;
  			flag = 0;
  			break;
  		}else{
  			a[i] /= tw;
  		}
  	}else{
  		ans = 0;
  		flag = 0;
  		break;
  	}
  }
  
  for(int i=0;i<n;i++){
  	x = lcm(x, a[i]);
  	if(m<x){
  		flag = 0;
  		ans = 0;
  		break;
  	}
  }
  
  
  
  
  if(flag){
	ans = (m-x)/(2*x);
	ans++;
  }
  
  cout<<ans<<endl;
}
