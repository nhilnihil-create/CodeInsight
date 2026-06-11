#include <iostream>
#include <vector>
int main(){
  long long n, m, t;
  std::cin >> n; std::cin >> m;
  
  // don't forget
  if (n == 1 || m == 1){
  	t = 1;
  }else{
	t = (n/2*2) * (m/2*2) /2;
  
    if (n%2==1 && m%2==1){
      t += m / 2 + n / 2 + 1;
    }else if (n%2 == 1){
      t += m / 2 + m % 2;
    }else if (m%2 == 1){
      t += n / 2 + n % 2;
    }

  }
  std::cout << t << std::endl;

}