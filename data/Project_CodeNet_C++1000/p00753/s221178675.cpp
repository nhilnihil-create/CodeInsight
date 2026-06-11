#include <iostream>
#include <cmath>
using namespace std;

const int MAXNUM = 300000;

bool prime[MAXNUM];

void eratos()
{
    prime[0] = prime[1] = false;

    for(int i=2; i<MAXNUM; i++)
	prime[i]=true;

    for(int i=2; i*i<MAXNUM; i++){
	if(prime[i]){
	    for(int j=i*i; j<MAXNUM;  j+=i)
		prime[j] = false;
	}
    }
}


int main()
{
  eratos();
  
    int N;
    while(cin >> N, N){
	int res = 0;

	for(int i=N+1; i<=2*N; i++)
	    if(prime[i]) res++;

	cout << res << endl;
    }
    
}