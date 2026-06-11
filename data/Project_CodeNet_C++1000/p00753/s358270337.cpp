#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//nツづ債甘慊づ慊づ按つ「ツづヲツ！
vector<int> sieve_of_eratosthenes(int n) {
  vector<int> primes(n);
  for (int i = 2; i < n; ++i)
    primes[i] = i;
  for (int i = 2; i*i < n; ++i)
    if (primes[i])
      for (int j = i*i; j < n; j+=i)
        primes[j] = 0;
  return primes;
}

int main()
{
	int n;
	vector<int> V=sieve_of_eratosthenes(123457*2);
	while(cin>>n,n){
		int count=0;
		for(int i=n+1;i<=n*2;i++)
			if(V[i]!=0) count++;
		cout<<count<<endl;
	}
	return 0;
}