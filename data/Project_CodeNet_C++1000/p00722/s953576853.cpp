#include <iostream>

#define MAX 1000001

bool is_prime[MAX];

int main(int argc,char* argv[]){
  
  for(int i = 0; i < MAX; i++){
    is_prime[i] = true;
  }

  is_prime[0] = is_prime[1] = false;

  for(int i = 2; i <= 1000; i++){
    if(is_prime[i]){
      for(int j = 2*i; j < MAX; j += i){
	is_prime[j] = false;
      }
    }
  }


  while(true){
    int a,d,n;

    std::cin >> a >> d >> n;

    if(a == 0 && d == 0 && n == 0){
      break;
    }

    int count = 0;
    for(int i = a; i < MAX; i += d){
      if(is_prime[i]){
	count++;
	if(count == n){
	  std::cout << i << std::endl;
	  break;
	}
      }
    }
  }
  
  return 0;
  
}