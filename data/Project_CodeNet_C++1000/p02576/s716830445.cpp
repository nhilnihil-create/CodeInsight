    #include<iostream>
    #include<cmath>
    using namespace std;
    void solution()
    {
    	long long int n, x, t,res; 
      cin >> n >> x >> t;
    	res = ceil(n * 1.0 / x);
    	cout << res*t<<"\n";
    	
    	
    }
    int main()
    {
      int t = 1; 
    	while (t--)
    		solution();
    	return 0;
    }