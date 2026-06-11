#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

int main()
{
	long N, A, B;
	cin >> N >> A >> B;
	
	long dist = B - A;
	
	if(dist % 2 == 0) cout << dist / 2 << endl;
	else{
		cout << min(A - 1, N - B) + 1 +  (dist - 1) / 2 << endl;  
		
	}
	
	return 0;

}