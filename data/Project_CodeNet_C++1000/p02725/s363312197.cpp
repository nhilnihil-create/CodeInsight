    #include <iostream>
    #include <algorithm>
     
    int main()
    {
      int k, n, a[200010];
      std::cin >> k >> n;
      
      for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
      }
      
      int max = 0;
      for (int i = 1; i < n; ++i) 
      {
        if (a[i] - a[i-1] > max)
          max = a[i] - a[i-1];
      }
      
      if (k+a[0] - a[n-1] > max)
        max = k+a[0] - a[n-1];
      
      std::cout << k-max;
    }