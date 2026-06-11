#include<iostream>

int main(){
	long long n,d,d2;
  	std::cin >> n >> d;
  	d2 = d*d;
  	int ans = 0;
  	for(int i=0; i<n; i++){
		long long x,y; std::cin >> x >> y;
      	long long dist2 = x*x + y*y;
      	if(dist2 <= d2) ans++;
    }
  	std::cout << ans << std::endl;
  	return 0;
}
