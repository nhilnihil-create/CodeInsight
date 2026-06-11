#include <iostream>

int main()
{
    int d, t, s;

    std::cin >> d >> t >> s;
      int dist = s * t;

  if( dist >= d ){
    
    

    std::cout << "Yes" << std::endl;
  }
  else{
    std::cout << "No" << std::endl;
  }
}