#include <bits/stdc++.h> 
using namespace std; 

int countDivisibles(int A, int B, int M) 
{  
	int counter = 0; 
	for (int i = A; i <= B; i++) 
		if (i % M == 0) 
			counter++; 

	return counter; 
} 


int main() 
{ 
	 int A, B, M;
	 cin >> A >> B >> M;
	cout << countDivisibles(A, B, M) << endl; 
	return 0; 
} 
