#include <iostream>
#define int long long 
using namespace std;

signed main() {
	int N, A, B, nb, ns;
	cin>>N>>A>>B;
	
	int answer = 0;
	answer = (N/(A+B))*A;
	if(N%(A+B) >= A)
	{
		answer += A;
		cout<<answer;
	}
	else
	{
		answer += (N%(A+B));
		cout<<answer;
	}

	
	return 0;
}